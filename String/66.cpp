// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> res;
    void findUtil(string &s, int i)
    {
        if (i == s.size() - 1)
        {
            res.push_back(s);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            findUtil(s, i + 1);
            swap(s[i], s[j]);
        }
        return;
    }
    vector<string> find_permutation(string S)
    {

        findUtil(S, 0);
        sort(res.begin(), res.end());
        return res;
        // Code here there
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends