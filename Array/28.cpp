// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        int k =0;
        
        while(k<n) {
            int i,j;
            i =k+1,j=n-1;
            while(i<j) {
                int sum =  A[i] + A[k] + A[j];
                if(sum == X)
                    return true;
                if(sum < X)
                    i++;
                else {
                    j--;
                }
            }
            k++;
        }
        return false;
        
        //Your Code Here
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends