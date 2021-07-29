// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isSafe(vector<vector<int>> &mat, int n, int m, int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1);
    }

    int orangesRotting(vector<vector<int>> &mat)

    {
        int n = mat.size();
        int m = mat[0].size();
        int time = -1;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (q.empty() == false)
        {
            int count = q.size();

            for (int k = 0; k < count; k++)
            {
                pair<int, int> index = q.front();
                int i = index.first;
                int j = index.second;
                for (int tol = 0; tol < 4; tol++)
                {
                    int r = dir[tol][0] + i;
                    int c = dir[tol][1] + j;
                    if (isSafe(mat, n, m, r, c))
                    {
                        mat[r][c] = 2;
                        q.push({r, c});
                    }
                }

                q.pop();
            }

            time++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends