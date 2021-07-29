// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    
	    vector<int>ans;
	    stack<int> temp;
	    temp.push(0);
	    bool visited[V];
	    for(int i=0;i<V;i++)
	        visited[i] = false;
	    int buf;
	    while(temp.empty() == false) {
	        buf = temp.top();
	        temp.pop();
	        if(visited[buf] == false) {
	            visited[buf]=true;
	            ans.push_back(buf);
	            for (auto it = adj[buf].rbegin(); it != adj[buf].rend(); ++it)
                    if(visited[*it] == false) {
	                    temp.push(*it);
	           
	                }
	        }
	        
	    }
	    // Code here
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends