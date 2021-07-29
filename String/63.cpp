// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string S)
    {
        int n = S.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                    dp[i][j] = 1;
                else if (g == 1)
                {
                    if (S[i] == S[j])
                        dp[i][j] = 2;
                }
                else
                {
                    if (S[i] == S[j])
                        dp[i][j] = dp[i + 1][j - 1] > 0 ? j - i + 1 : 0;
                    else
                        dp[i][j] = 0;
                }
            }
        }
        int len = 0;
        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] > len)
                {
                    len = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }

        return S.substr(start, len);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends