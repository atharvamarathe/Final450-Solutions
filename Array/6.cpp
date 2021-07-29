// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        
         map<int,int>m1;
         for(int i = 0;i<n;i++) {
             m1.insert(make_pair(a[i],a[i]));
         }
         
         for(int i = 0;i<m;i++) {
             if(m1.count(b[i]) == 0)
                m1.insert(make_pair(b[i],b[i]));
         }
         
         return m1.size();
        //code here
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends