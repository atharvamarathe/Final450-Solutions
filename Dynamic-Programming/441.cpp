// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int dp[S1.length() + 1][S2.length() + 1];
        int res = 0;
        for (int i = 0; i <= S1.length(); i++)
        {
            for (int j = 0; j <= S2.length(); j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    // cout << dp[i][j] << " ";
                }
                else
                {
                    if (S1[i - 1] == S2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        res = max(res, dp[i][j]);
                        // cout << dp[i][j] << " ";
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
            // cout << endl;
        }

        return res;
        // your code here
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
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends