// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void toposortUtil(stack<int>&s1,vector<bool>&visited,int V,vector<int>adj[]) {
	    
	    visited[V] = true;
	    
	    for(auto v: adj[V]) {
	        
	        if(!visited[v])
	            toposortUtil(s1,visited,v,adj);
	    }
	    
	    s1.push(V);
	    
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>s1;
	    vector<bool> visited(V,false);
	    for(int i = 0;i< V;i++) {
	        
	        if(visited[i] == false)
	            toposortUtil(s1,visited,i,adj);
	    }
	    
	    vector<int>ans;
	    while(!s1.empty()) {
	        ans.push_back(s1.top());
	        s1.pop();
	    }
	    
	    return ans;
	    
	    // code here
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends