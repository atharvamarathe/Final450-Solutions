#include <iostream>
#include <vector>
#include <queue>


using namespace std;

//src assumed to be at 0
int longestPathInDAG(vector<int>adj[],int V) {

    vector<int> inDegree(V,0);
    vector<int>dis(V,INT_MIN);
    vector<int>toposort;
    dis[0] = 0;
    for(int i = 0;i<V;i++) {
        for(auto v:adj[i]) {
            inDegree[v]+=1;
        }
    }
    queue<int> q;
    for(int i =0;i<V;i++) {
        if(inDegree[i] == 0) {
            toposort.push_back(i);
            q.push(i);
        }
    }
    // int count = 0;
    int temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        for(int i = 0;i<adj[temp].size();i++) {
            if(--inDegree[adj[temp].at(i)] == 0) {
                toposort.push_back(adj[temp].at(i));
                q.push(adj[temp].at(i));
            }
        }
        
        // count +=1;
    }
    for(int i = 0;i<toposort.size();i++) {
        int temp = toposort[i];
        if(dis[temp] != INT_MIN) {
            for(int j = 0;j<adj[temp].size();j++) {
                if(dis[adj[temp][j]] < dis[temp] + adj[temp][j]) {
                    dis[adj[temp][j]] = dis[temp] + adj[temp][j];
                }
            }
        }
        
    }
}