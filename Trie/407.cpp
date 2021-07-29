// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    set<int>s;
    vector<int>buf;
    for(int i=0;i<row;i++)
    {
        int ans=0;
        int m=1;
        for(int j=col-1;j>=0;j--)
        {
            int x = m*M[i][j];
            ans+=x;
            m=m*10;
        
        }
        
        
        if(s.find(ans)==s.end())
        {   
            s.insert(ans);
            buf.push_back(i);
        }
    }
    vector<vector<int>>ans;
    for(int i = 0;i<buf.size();i++) {
        vector<int>temp;
        for(int j =0;j<col;j++) {
            temp.push_back(M[buf[i]][j]);
        }
        ans.push_back(temp);
    }
    return ans;
//Your code here
}