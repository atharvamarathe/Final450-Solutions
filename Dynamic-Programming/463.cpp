// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[210][210][3];
    int rec(string &s, int i, int j, bool istrue)
    {
        if (i > j)
        {
            return dp[i][j][istrue] = 0;
        }
        else if (i == j)
        {
            return dp[i][j][istrue] = (istrue) ? ((s[i] == 'T') ? 1 : 0) : ((s[i] == 'F') ? 1 : 0);
        }
        else if (dp[i][j][istrue] != -1)
        {
            return dp[i][j][istrue];
        }
        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {

            int lT;
            if (dp[i][k - 1][1] != -1)
                lT = dp[i][k - 1][1];
            else
                lT = rec(s, i, k - 1, true);

            int lF;
            if (dp[i][k - 1][0] != -1)
                lF = dp[i][k - 1][0];
            else
                lF = rec(s, i, k - 1, false);

            int rT;
            if (dp[k + 1][j][1] != -1)
                rT = dp[k + 1][j][1];
            else
                rT = rec(s, k + 1, j, true);

            int rF;
            if (dp[k + 1][j][0] != -1)
                rF = dp[k + 1][j][0];
            else
                rF = rec(s, k + 1, j, false);

            if (s[k] == '&')
            {
                if (istrue)
                {
                    ans += (lT * rT);
                    dp[i][j][istrue] = ans;
                }
                else
                {
                    ans += (lT * rF + lF * rT + rF * lF);
                    dp[i][j][istrue] = ans;
                }
            }
            else if (s[k] == '|')
            {
                if (istrue)
                {
                    ans += (lT * rF + lF * rT + lT * rT);
                    dp[i][j][istrue] = ans;
                }
                else
                {
                    ans += (lF * rF);
                    dp[i][j][istrue] = ans;
                }
            }
            else if (s[k] == '^')
            {
                if (istrue)
                {
                    ans += (lF * rT + lT * rF);
                    dp[i][j][istrue] = ans;
                }
                else
                {
                    ans += (lT * rT + lF * rF);
                    dp[i][j][istrue] = ans;
                }
            }
            // cout<<ans<<endl;
        }
        return dp[i][j][istrue] = ans % 1003;
    }

    int countWays(int N, string S)
    {
        memset(dp, -1, sizeof(dp));
        return rec(S, 0, N - 1, true);
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
} // } Driver Code Ends