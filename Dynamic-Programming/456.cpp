// { Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long int disarrange(int N)
    {
        long long int MOD = 1000000007;
        if (N < 2)
            return 0;
        long long int dp[N + 1];
        dp[0] = dp[1] = 0;
        dp[2] = 1;
        if (N == 2)
            return 1;
        for (int i = 3; i <= N; i++)
        {
            dp[i] = ((i - 1) * ((dp[i - 1] + dp[i - 2]) % MOD)) % MOD;
        }

        return dp[N];
        // code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.disarrange(N) << "\n";
    }
    return 0;
} // } Driver Code Ends