// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int j = m - 1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                if (j == m - 1)
                    dp[i][j] = M[i][j];
                else if (i == 0)
                    dp[i][j] = M[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
                else if (i == n - 1)
                    dp[i][j] = M[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
                else
                {
                    dp[i][j] = M[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
} // } Driver Code Ends