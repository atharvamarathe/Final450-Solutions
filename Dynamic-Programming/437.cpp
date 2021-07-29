// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int maxSubstring(string S)
    {
        int dp[S.length()];
        dp[0] = (S[0] == '0') ? 1 : -1;
        for (int i = 1; i < S.length(); i++)
        {
            if (S[i] == '0')
            {
                dp[i] = max(1, dp[i - 1] + 1);
            }
            else if (S[i] == '1')
            {
                dp[i] = max(dp[i - 1] - 1, -1);
            }
        }
        int res = -1;
        for (int i = 0; i < S.length(); i++)
        {
            res = max(res, dp[i]);
        }

        return res;
        // Your code goes here
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends