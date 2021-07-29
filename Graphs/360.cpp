// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCyclicConntected(vector<int>adj[],int s,int V,vector<bool>& visited) {
	    
	    queue<int>q;
	   // bool visited[V];
	    int parent[V];
	    for(int i = 0;i<V;i++){
	       // visited[i] = false;
	        parent[i] = -1;
	    }
	    visited[s] = true;
	    q.push(s);
	    int temp;
	    while(!q.empty()) {
	        temp = q.front();
	        q.pop();
	        
	        for(auto v:adj[temp]) {
	            if(!visited[v]) {
	                visited[v] = true;
	                parent[v] = temp;
	                q.push(v);
	            }
	            else if(parent[temp] != v) {
	                return true;
	            }
	        }
	    }
	    
	    return false;
	    // Code here
	}
	
	bool isCycle(int V, vector<int>adj[]) {
	     vector<bool> visited(V, false);
 
        for (int i = 0; i < V; i++)
            if (!visited[i] && isCyclicConntected(adj, i,V, visited))
                return true;
        return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends