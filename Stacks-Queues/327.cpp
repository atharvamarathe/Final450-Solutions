// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            pair<int, int> key = q.front();
            q.pop();
            int x = key.first;
            int y = key.second;
            for (int i = 0; i < 4; i++)
            {
                int r = x + dx[i];
                int c = y + dy[i];
                if (r >= 0 && r < n && c >= 0 && c < m)
                {
                    if (ans[r][c] > ans[x][y] + 1)
                    {
                        ans[r][c] = ans[x][y] + 1;
                        q.push({r, c});
                    }
                }
            }
        }
        return ans;
        // Code here
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
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends