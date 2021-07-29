// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void swap(int arr[],int a,int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    #define GETLCHILD(i) (2*i+1)
    #define GETRCHILD(i) (2*i+2)
    #define GETPARENT(i) ((i-1)/2)
    void heapify(int arr[],int n,int i) {
        int lchild = GETLCHILD(i);
        int rchild = GETRCHILD(i);
        int largest = i;
        
        if(lchild < n && arr[lchild] > arr[largest]) {
            largest = lchild;
        }
        if(rchild < n && arr[rchild] > arr[largest]) {
            largest = rchild;
        }
        if(largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr,n,largest);
        }
    }
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int>ans;
	    for(int i = n/2 -1 ;i>=0;i--) {
	        heapify(arr,n,i);
	    }
	    int i = 0;
	    int j = n-1;
	    while(i < k && j >= 0) {
	        ans.push_back(arr[0]);
	        swap(arr,j,0);
	        heapify(arr,j,0);
	        j--;
	        i++;
	    }
	    return ans;
	    
	    // code here
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends 