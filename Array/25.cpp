// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        map<int,int>m1;
        int count = n/k;
        int ans =0;
        for(int i =0;i<n;i++) {
            if(m1.find(arr[i]) == m1.end()) {
                m1.insert({arr[i],1});
            }
            else if(m1.find(arr[i]) != m1.end()) {
                map<int,int>::iterator a = m1.find(arr[i]);
                a->second++;
            }
        }
        
        for(auto it = m1.begin();it!= m1.end();it++) {
            if(it->second > count)
                ans++;
        }
        return ans;
        // Your code here
    }
};


// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends 