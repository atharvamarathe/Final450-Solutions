// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    
	    queue<int>temp;
    vector<int>answer;
    bool visited[V];
    for(int i =0;i<V;i++) {
        visited[i] = false;
    }
    int buf,buf1;
    answer.push_back(0);
    visited[0] = true;
    temp.push(0);
    while(temp.empty() == false) {

        buf = temp.front();
        temp.pop();
        for(auto& i:adj[buf]) {
            if(visited[i]!=true) {
                answer.push_back(i);
                visited[i] = true;
                temp.push(i);
            }
        }
    }

    return answer;
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
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends