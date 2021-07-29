// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kadane(vector<int> nums, int n)
    {
        int overall = INT_MIN;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            if (overall < curr)
                overall = curr;
            if (curr < 0)
                curr = 0;
        }
        return overall;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {

        int max1 = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            vector<int> ans(C);
            for (int j = i; j < R; j++)
            {
                for (int col = 0; col < C; col++)
                {
                    ans[col] += M[j][col];
                }
                max1 = max(max1, kadane(ans, C));
            }
        }

        return max1;
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
} // } Driver Code Ends