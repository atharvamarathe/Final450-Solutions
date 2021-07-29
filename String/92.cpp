// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        int hash[256] = {0};
        int unique = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (hash[p[i]] == 0)
                unique++;
            hash[p[i]]++;
        }

        int count = INT_MAX;
        int start = 0;
        int i = 0, j = 0;
        while (j < s.size())
        {
            hash[s[j]]--;
            if (hash[s[j]] == 0)
            {
                unique--;
            }
            if (unique == 0)
            {
                while (unique == 0)
                {
                    if (count > j - i + 1)
                    {
                        count = min(count, j - i + 1);
                        start = i;
                    }
                    hash[s[i]]++;
                    if (hash[s[i]] > 0)
                        unique++;
                    i++;
                }
            }
            j++;
        }

        if (count == INT_MAX)
            return "-1";
        return s.substr(start, count);
        // Your code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} // } Driver Code Ends