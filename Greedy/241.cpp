// Code not submitted. So no Gurantee of working 100%. But Logical is nearly correct.
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int DFSUtil(vector<int>adj[],int V,vector<bool>&visited,int a) {
        
        visited[a] = true;
        int temp = a;
        for(int i = 0;i<adj[a].size();i++) {
            if(!visited[adj[a][i]])
                temp = DFSUtil(adj,V,visited,adj[a][i]);
        }
        return temp;
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<int>adj[n];
        
        for(int i = 0;i< a.size();i++) {
            adj[i].push_back(b[i]);
            // adj[j].push_back(a[i]);
        }
        // int count = 0;
        pair<int,pair<int,int>>pipes[n];
        for(int i = 0;i<n;i++) {
            pipes[i] = make_pair(d[i],make_pair(a[i],b[i]));
        }
        sort(pipes,pipes+n);
        vector<vector<int>>res;
        vector<int>temp;
        vector<bool>visited(n,false);
        for(int i =0;i<n;i++) {
            if(!visited[pipes[i].second.first]) {
                temp.push_back(pipes[i].second.first);
                temp.push_back(DFSUtil(adj,n,visited,pipes[i].second.first));
                temp.push_back(pipes[i].first);
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
        
        
        
        
        // code here
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends