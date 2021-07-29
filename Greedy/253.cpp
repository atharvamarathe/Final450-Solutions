// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int sum(long long int a[],int n) {
        long long int s = 0;
        for(int i =0;i<n;i++) {
            s += a[i];
        }
        return s;
    }
    long long int getMinNum(long long int a[],int n) {
        long long int min = a[0];
        for(int i = 1;i<n;i++) {
            if(min > a[i])
                min = a[i];
        }
        return min;
    }
    long long int maximizeSum(long long int a[], int n, int k)
    {
        
        sort(a,a+n);
        int i = 0;
        while(k > 0 && a[i] < 0) {
            a[i] = -a[i];
            i++;
            k--;
        }
        long long int ans = sum(a,n);
        long long int min = getMinNum(a,n);
        // printf("ans is and mi is %d , %lld\n",ans,min);
        if(k % 2== 1)
            ans -= 2*min;
        return ans;
        // Your code goes here
        
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends