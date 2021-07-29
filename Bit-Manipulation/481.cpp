// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void generatePossibleStrings(string str, vector<string> &res, int index = 0, string curr = "")
    {
        if (index == str.size())
        {
            if (curr != "")
            {
                res.push_back(curr);
            }

            return;
        }

        generatePossibleStrings(str, res, index + 1, curr);
        generatePossibleStrings(str, res, index + 1, curr + str[index]);
    }

public:
    vector<string> AllPossibleStrings(string str)
    {
        vector<string> res;

        generatePossibleStrings(str, res);

        sort(res.begin(), res.end());

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends