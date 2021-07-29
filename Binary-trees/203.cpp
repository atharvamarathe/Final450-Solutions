#include <iostream>
#include <vector>
#include <queue>

using namespace std;



bool isCyclic(int a,vector<bool>&visited,vector<int>adj[],int parent,int V) {

    visited[a] = true;

    vector<int>::iterator it;

    for(it=adj[a].begin();it!=adj[a].end();it++) {
        if(!visited[*it]) {
            if(isCyclic(*it,visited,adj,a,V))
                return true;
        }
        else if(*it != parent) {
            return true;
        }   
    }   
    return false;
}
bool isTree(vector<int>adj[],int V) {
    vector<bool>visited(V,false);
    if(isCyclic(0,visited,adj,-1,V))
        return false;
    for(int i = 0;i<V;i++) {
        if(!visited[i])
            return false;
    }
    return true;
}