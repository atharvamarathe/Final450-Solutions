// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    #define mod 1000000007
    long long countWays(int n, int k){
        if(n==0)
            return 0;
        if(n==1)
            return k;
            
        long long int same = k % mod;
        long long int diff = k*(k-1) % mod;
        long long int total = (same + diff) % mod;
        
        for(int i = 3;i<=n;i++) {
            same = diff % mod;
            diff = (total * (k-1)) % mod;
            total = (same + diff) % mod;
        }
        return total % mod;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends