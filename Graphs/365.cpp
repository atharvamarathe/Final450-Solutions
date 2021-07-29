#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void DFSUtil(vector<int>adj[],int V,vector<bool>&visited,int a) {
        visited[a] = true;
        for(int i = 0;i<adj[a].size();i++) {
            if(!visited[adj[a][i]])
                DFSUtil(adj,V,visited,adj[a][i]);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool>visited(n,false);
        int count = 0;
        if(connections.size() < n-1)
            return -1;
        else {
            vector<int>adj[n];
            for(int i = 0;i<connections.size();i++) {
                adj[connections[i][0]].push_back(connections[i][1]);
                adj[connections[i][1]].push_back(connections[i][0]);
            }
            for(int i =0;i<n;i++) {
                if(!visited[i]) {
                    count++;
                    DFSUtil(adj,n,visited,i);
                }
            }
            
            return count-1;
            
        }
        
    }
};