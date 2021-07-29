// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    
	    vector<int>neg;
	    vector<int>pos;
	    for(int i =0;i<n;i++) {
	        if(arr[i] < 0)
	            neg.push_back(arr[i]);
	       else 
	            pos.push_back(arr[i]);
	    }
	    
	    int i=0, j =0,k=0;
	    while(i<n && j < pos.size() && k < neg.size()) {
	       if(i%2==0 && j < pos.size()) {
	           arr[i++] = pos[j++];
	           //j++;
	       }
	       else if(i%2 != 0 && k < neg.size())
	            arr[i++] = neg[k++];
	           
	    }
	    while(k < neg.size()) {
	        arr[i++] = neg[k++];
	    }
	    while(j < pos.size()) {
	        arr[i++] = pos[j++];
	    }
	    
	    
	   
	    // code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends