// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool check(int i, int j, int wl, int pl, string &w, string &p)
    {
        if (i == wl && j == pl)
            return true;
        if (i == wl || j == pl)
            return false;
        if (w[i] == '?' || w[i] == p[j])
        {
            return check(i + 1, j + 1, wl, pl, w, p);
        }
        if (w[i] == '*')
        {
            for (; j < pl; j++)
                if (check(i + 1, j, wl, pl, w, p))
                    return true;
        }

        return false;
    }
    bool match(string wild, string pattern)
    {

        wild += '#';
        pattern += '#';
        return check(0, 0, wild.size(), pattern.size(), wild, pattern);

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
        string wild, pattern;
        cin >> wild >> pattern;

        Solution ob;
        if (ob.match(wild, pattern))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} // } Driver Code Ends