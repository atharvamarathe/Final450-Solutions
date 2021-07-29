// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N - 1][N - 1];
        int i, j;
        for (int g = 0; g < N - 1; g++)
        {
            for (i = 0, j = g; j < N - 1; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = 0;
                }
                else if (g == 1)
                {
                    dp[i][j] = arr[i] * arr[j] * arr[j + 1];
                }
                else
                {
                    int min1 = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        int leftCost = dp[i][k];
                        int rightCost = dp[k + 1][j];
                        int mulCost = arr[i] * arr[k + 1] * arr[j + 1];
                        int totalCost = leftCost + rightCost + mulCost;
                        min1 = min(min1, totalCost);
                    }
                    dp[i][j] = min1;
                }
            }
        }
        return dp[0][N - 2];
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends