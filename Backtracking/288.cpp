// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>res;
	    void find_permutationUtil(int c,int k, map<char,int>m1,string s) {
	       // printf("C and K is %d and %d\n",c,k);
	        if(c >= k) {
	            res.push_back(s);
	           // printf("Hello");
	            return;
	        }
	        for(auto it=m1.begin();it!=m1.end();it++) {
	            if(it->second > 0) {
	                it->second -= 1;
	                find_permutationUtil(c+1,k,m1,s+it->first);
	                it->second +=1;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    map<char,int>m1;
		    for(int i = 0;i<S.length();i++) {
		        if(m1.find(S[i])== m1.end())
		            m1.insert(make_pair(S[i],1));
		        else {
		            map<char,int>::iterator a;
		            a = m1.find(S[i]);
		            a->second++;
		          //  m1[S[i]]++;
		        }
		    }
		    string ans;
		    find_permutationUtil(0,S.length(),m1,ans);
		    return res;
		    // Code here there
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends