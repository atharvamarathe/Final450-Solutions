class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
            return "";
        int i = 0, j = 0;
        int n = s.size();
        //initialize P[n][n], we only need half of P, and initialize it like: (e.g. : s="abbc")
        vector<vector<bool>> P(n, vector<bool>(n, false));
        for (int x = 0; x < n; x++)
        {
            P[x][x] = true;
            if (x == n - 1)
                break;
            P[x][x + 1] = (s[x] == s[x + 1]);
        }
        //dp
        for (int i = n - 3; i >= 0; --i)
        {
            for (int j = i + 2; j < n; ++j)
            {
                P[i][j] = (P[i + 1][j - 1] && s[i] == s[j]);
            }
        }
        //get maxstr result
        int max = 0;
        string maxstr = "";
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (P[i][j] == true and j - i + 1 > max)
                {
                    max = j - i + 1;
                    maxstr = s.substr(i, j - i + 1);
                }
            }
        }
        return maxstr;
    }
};