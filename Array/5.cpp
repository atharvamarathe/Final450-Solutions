// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int pos = 0;
        vector<int>neg,neg1;
        for(int i =0;i<n;i++) {
            if(arr[i] >= 0)
                neg.push_back(arr[i]);
            else if(arr[i] < 0)
                neg1.push_back(arr[i]);
        }
        int j = 0;
        for(int i =0;i<neg.size();i++) {
            arr[j] = neg[i];
            j++;
        }
        for(int i = 0;i<neg1.size();i++) {
            arr[j] = neg1[i];
            j++;
        }
        
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends