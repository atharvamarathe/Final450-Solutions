// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string>res;
    void wordBreakUtil(vector<string>& dict, string s,int n,string ans) {
        if(s.length() == 0) {
            res.push_back(ans.substr(0,ans.size()-1));
            return;
        }
        for(int i = 0;i<s.length();i++) {
            string left = s.substr(0,i+1);
            if(find(dict.begin(),dict.end(),left) != dict.end()) {
                string right = s.substr(i+1);
                wordBreakUtil(dict,right,right.length(),ans+left+" ");
            }
        }
        
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        string ans = "";
        wordBreakUtil(dict,s,n,ans);
        return res;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends