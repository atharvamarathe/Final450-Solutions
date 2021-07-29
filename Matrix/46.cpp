#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            mn = min(mn, matrix[i][0]);
            mx = max(mx, matrix[i][c - 1]);
        }

        int dezired = (r * c + 1) / 2;
        while (mn < mx)
        {
            int mid = mn + (mx - mn) / 2;
            int count = 0;

            for (int i = 0; i < r; i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            if (count < dezired)
                mn = mid + 1;
            else
                mx = mid;
        }
        return mn;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
} // } Driver Code Ends