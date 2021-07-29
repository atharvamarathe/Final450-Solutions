// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int keypad[4][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9},
                        {-1, 0, -1}};
    long long dp[10][26];
    long long calculate(int n, int i, int j)
    {
        if (n == 1)
            return 1;
        if (dp[keypad[i][j]][n] != -1)
            return dp[keypad[i][j]][n];
        long long a = calculate(n - 1, i, j);
        long long up = 0, left = 0, right = 0, down = 0;
        if (i - 1 >= 0 && keypad[i - 1][j] != -1)
            up = calculate(n - 1, i - 1, j);
        if (j - 1 >= 0 && keypad[i][j - 1] != -1)
            left = calculate(n - 1, i, j - 1);
        if (j + 1 < 3 && keypad[i][j + 1] != -1)
            right = calculate(n - 1, i, j + 1);
        if (i + 1 < 4 && keypad[i + 1][j] != -1)
            down = calculate(n - 1, i + 1, j);
        return dp[keypad[i][j]][n] = up + left + right + down + a;
    }

    long long getCount(int N)
    {
        dp[10][N + 1];
        long long ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (keypad[i][j] != -1)
                    ans += calculate(N, i, j);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}
// } Driver Code Ends