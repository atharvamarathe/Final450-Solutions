// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

// the thing is to store the prefix sum till each index, Now,
// Case I(sum not zero):
// for example sum till index 5=10, and sum till index 10 is also =10, then what we can say is that the sum from 5
// to 10 is zero.

// Case iI(sum = zero):
// If sum become zero, then the subarray from starting to this index have some zero and we have to consider them.

class Solution
{
public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {
        unordered_map<int, int> m1;
        m1[0] = 1;
        ll sum = 0, counter = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            counter += (m1[sum]++);
        }

        return counter;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; //input size of array

        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
} // } Driver Code Ends