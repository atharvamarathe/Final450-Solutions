// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int getmax(int a, int b)
    {
        if (a >= b)
            return a;
        else
            return b;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {

        int dp[n + 1][W + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j < W + 1; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (wt[i - 1] <= j)
                {
                    dp[i][j] = getmax(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][W];
        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends