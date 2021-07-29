// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   vector<int> inDegree(V,0);
	   for(int i = 0;i<V;i++) {
	       for(auto v:adj[i]) {
	           inDegree[v]+=1;
	       }
	   }
	   queue<int> q;
	   for(int i =0;i<V;i++) {
	       if(inDegree[i] == 0)
	            q.push(i);
	   }
	   int count = 0;
	   int temp;
	   while(!q.empty()) {
	       temp = q.front();
	       q.pop();
	       for(int i = 0;i<adj[temp].size();i++) {
	           if(--inDegree[adj[temp].at(i)] == 0)
	                q.push(adj[temp].at(i));
	       }
	       
	       count +=1;
	   }
	   
	   if(count != V)
	        return true;
	   else 
	        return false;
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends