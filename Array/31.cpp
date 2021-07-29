// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        int minimum = n+1;
        int j = 0;
        int sum = 0;
        int i =0;
        while(i<n) {
            while(sum <= x && i<n) {
                sum += arr[i++];
                // i++;
            }
            while(sum > x && j < n) {
                minimum = min(i-j,minimum);
                sum -= arr[j++];
                // j++;
            }
        }
        
        return minimum;
        // Your code goes here   
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends