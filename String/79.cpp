// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    bool search2D(vector<vector<char>> &grid, string word, int x, int y)
    {
        if (grid[x][y] != word[0])
            return false;
        int len = word.size();
        for (int i = 0; i < 8; i++)
        {
            int k, rd = x + dx[i], cd = y + dy[i];
            for (k = 1; k < len; k++)
            {
                if (rd >= grid.size() || rd < 0 | cd >= grid[0].size() || cd < 0)
                    break;
                if (grid[rd][cd] != word[k])
                    break;
                rd += dx[i], cd += dy[i];
            }
            if (k == len)
                return true;
        }
        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (search2D(grid, word, i, j))
                    ans.push_back({i, j});
            }
        }

        return ans;
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
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
    }
    return 0;
} // } Driver Code Ends