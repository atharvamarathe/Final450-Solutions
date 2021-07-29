// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        long long int mod = 1000000007;
        int n = str.length();
        long long int dp[n][n];
        for (int g = 0; g < n; g++)
        {
            for (int j = g, i = 0; j < n; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = 1;
                }
                else if (g == 1)
                {
                    if (str[i] == str[j])
                        dp[i][j] = 3;
                    else
                        dp[i][j] = 2;
                }
                else if (str[i] == str[j])
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % mod;
                }
                else
                {
                    long long a = (dp[i][j - 1] + dp[i + 1][j]) % mod;
                    long long b = dp[i + 1][j - 1];
                    dp[i][j] = ((a - b) % mod + mod) % mod;
                }
            }
        }
        return dp[0][n - 1];
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
} // } Driver Code Ends