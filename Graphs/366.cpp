#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    bool isAdjecent(string a,string b) {
        int count = 0;
        for(int i = 0;i<a.length() && i<b.length();i++) {
            if(a[i] != b[i])
                count++;
        }
        if(count == 1)
            return true;
        return false;
    }
    int BFSUtil(vector<int>adj[],int src,int dest,int V) {
        if(src == dest)
            return 1;
        queue<int>q1;
        vector<bool>visited(V,false);
        vector<int>dist(V,INT_MAX);
        int count = 0;
        dist[src] = 0;
        q1.push(src);
        while(!q1.empty()) {
            int temp = q1.front();
            q1.pop();
            for(int i = 0;i<adj[temp].size();i++) {
                if(!visited[adj[temp][i]]) {
                    visited[adj[temp][i]] = true;
                    dist[adj[temp][i]] = dist[temp] +1;
                    q1.push(adj[temp][i]);
                    if(adj[temp][i] == dest) {
                        count=dist[adj[temp][i]];
                        return count+1;
                    }
                }
            }
        }
        
        return -1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<int>adj[wordList.size()+1];
        vector<bool>visited(wordList.size(),false);
        int dest=-1;int src =-1;
        for(int i = 0;i<wordList.size();i++) {
            if(wordList[i] == endWord)
                dest = i;
            if(wordList[i] == beginWord)
                src = i;
            for(int j = i+1;j<wordList.size();j++) {
                
                if(isAdjecent(wordList[i],wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(dest == -1)
            return 0;
        int count=0;
        int i =0;
        for(i =0;i<wordList.size();i++) {
            if(isAdjecent(beginWord,wordList[i]))
                break;
        }
        if(i == wordList.size())
            return 0;
        if(src == -1) {
            count = BFSUtil(adj,i,dest,wordList.size());

            return count +1;
        }
        else 
            count = BFSUtil(adj,src,dest,wordList.size());
        return count;
    }
};