// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    bool solve(int dp[][1001], string A, string B, string C, int n, int m, int len)
    {
        if (len == 0)
            return true;
        if (dp[n][m] != -1)
            return dp[n][m];
        int a = 0, b = 0;
        if (n - 1 >= 0 && A[n - 1] == C[len - 1])
            a = solve(dp, A, B, C, n - 1, m, len - 1);
        if (m - 1 >= 0 && B[m - 1] == C[len - 1])
            b = solve(dp, A, B, C, n, m - 1, len - 1);
        return a or b;
    }
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C)
    {
        int dp[1001][1001];
        if (A.length() + B.length() != C.length())
            return false;

        memset(dp, -1, sizeof(dp));
        return solve(dp, A, B, C, A.length(), B.length(), C.length());
        //Your code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends