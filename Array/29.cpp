// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        
        int left[n],right[n];
        int leftmax=0;
        for(int i = 0;i<n;i++) {
            left[i] = max(leftmax,arr[i]);
            leftmax = left[i];
        }
        int rightmax = 0;
        for(int i = n-1;i>=0;i--) {
            right[i] = max(rightmax,arr[i]);
            rightmax = right[i];
        }
        int ans = 0;
        for(int i =0;i<n;i++) {
            ans += min(left[i],right[i]) - arr[i];
        }
        
        return ans;
        // Code here
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends