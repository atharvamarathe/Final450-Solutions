// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution {
public:
    bool dfs(int u,vector<pair<int,int>>graph[],bool visited[],int w,int k) {
        if(w>=k)
            return true;
        visited[u] = true;
        for(auto v:graph[u]) {
            if(visited[v.first] == false) {
                if(dfs(v.first,graph,visited,w+v.second,k)) {
                    return true;
                }
            }
        }
        visited[u] = false;
        return false;
        
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    {
        // vector<bool>visited(V,false);
        vector<pair<int,int>>graph[V];
        for(int i =0;i<3*E;i+=3) {
            graph[a[i]].push_back({a[i+1],a[i+2]});
            graph[a[i+1]].push_back({a[i],a[i+2]});
        }
        bool visited[V];
        memset(visited,0,sizeof(visited));
        if(dfs(0,graph,visited,0,k)) {
            return true;
        }
        return false;
        
        
        //  Code Here
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends