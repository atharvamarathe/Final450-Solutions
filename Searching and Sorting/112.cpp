// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int dp[n];
        dp[0] = arr[0];
        dp[1] = max(arr[1], arr[0]);
        int res = arr[0];
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
        }
        return dp[n - 1];
        // Your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking number of houses
        int n;
        cin >> n;
        int a[n];

        //inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        //calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends