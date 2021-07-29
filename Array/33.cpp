// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    
    int count = 0;
    for(int i =0;i<n;i++) {
        if(arr[i] <= k)
            count++;
    }
    int bad = 0;
    for(int i =0;i<count;i++) {
        if(arr[i] > k)
            bad++;
    }
    int i =0,j=count-1;
    int ans = 100000001;
    while(j<n) {
        ans = min(ans,bad);
        j++;
        if(j<n && arr[j] > k)
            bad++;
        if(arr[i] > k)
            bad--;
        i++;
    }
    if(ans == 100000001)
        return 0;
    return ans;
    // Complet the function
}
