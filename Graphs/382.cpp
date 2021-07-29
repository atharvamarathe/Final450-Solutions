// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void FillUtil(int V,vector<int>adj[],bool visited[],stack<int>&s1) {
	    visited[V] = true;
	    
	    for(int i = 0;i<adj[V].size();i++) {
	        if(!visited[adj[V][i]])
	            FillUtil(adj[V][i],adj,visited,s1);
	    }
	    
	    s1.push(V);
	}
	void DFSUtil(int v,vector<int>adj[],bool visited[]) {
	    visited[v] = true;
	    
	    for(int i =0;i<adj[v].size();i++) {
	        if(!visited[adj[v][i]])
	            DFSUtil(adj[v][i],adj,visited);
	    }
	}
	
	void DFS(vector<int>adj[],int V,stack<int>&s1) {
	    bool visited[V];
	    fill(visited,visited+V,false);
	    for(int i = 0;i<V;i++) {
	        if(!visited[i])
	            FillUtil(i,adj,visited,s1);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        int count = 0;
        
        stack<int>s1;
        DFS(adj,V,s1);
        
        vector<int> ans[V];
        for(int i = 0;i<V;i++) {
	        
	        vector<int>::iterator it;
	        for(it = adj[i].begin();it!=adj[i].end();it++) {
	            
	            ans[*it].push_back(i);
	        }
	    }
        bool visited[V];
        fill(visited,visited+V,false);
        
        while(!s1.empty()) {
            int temp = s1.top();
            s1.pop();
            
            if(!visited[temp]) {
                
                DFSUtil(temp,ans,visited);
                count++;
            }
        }
        
        return count;
        //code here
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends