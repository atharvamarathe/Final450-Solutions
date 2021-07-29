// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void findPathUtil(string str,int curr_i,int curr_j,vector<vector<int>> &maze,vector<string> &ans,int n) {
        
        if(curr_i >= 0 && curr_i < n && curr_j >= 0 && curr_j < n && maze[curr_i][curr_j]) {
            
            if(curr_i ==n-1 && curr_j == n-1) {
                ans.push_back(str);
                return ;
            }
            maze[curr_i][curr_j] = 0;
            findPathUtil(str+"D",curr_i+1,curr_j,maze,ans,n);
            findPathUtil(str+"L",curr_i,curr_j-1,maze,ans,n);
            findPathUtil(str+"R",curr_i,curr_j+1,maze,ans,n);
            findPathUtil(str+"U",curr_i-1,curr_j,maze,ans,n);
            maze[curr_i][curr_j] = 1;
        }
        
        return;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        string str;
        vector<string>ans;
        findPathUtil(str,0,0,m,ans,n);
        return ans;
        


        // Your code goes here
    }  
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends