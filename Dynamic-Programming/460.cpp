// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        bool dp[n][n];
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                    dp[i][j] = true;
                else if (g == 1)
                {
                    if (str[i] == str[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if (str[i] == str[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                    }
                    else
                        dp[i][j] = false;
                }
            }
        }

        int ans[n];
        ans[0] = 0;
        for (int j = 1; j < n; j++)
        {
            if (dp[0][j])
                ans[j] = 0;
            else
            {
                int min1 = INT_MAX;
                for (int i = j; i >= 1; i--)
                {
                    if (dp[i][j])
                    {
                        if (ans[i - 1] < min1)
                            min1 = ans[i - 1];
                    }
                }
                ans[j] = min1 + 1;
            }
        }
        return ans[n - 1];

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
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
} // } Driver Code Ends