// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<stack<int>>a(n+1);
        vector<queue<int>>b(n+1);
        
        for(int i =0;i<2*e;i+=2) {
            a[A[i]].push(A[i+1]);
            b[B[i]].push(B[i+1]);
        }
        for(int i =1;i<=n;i++) {
            while(!a[i].empty() && !b[i].empty()) {
                int temp1 = a[i].top();
                int temp2 = b[i].front();
                if(temp1 != temp2)
                    return false;
                a[i].pop();
                b[i].pop();    
            }
            
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends