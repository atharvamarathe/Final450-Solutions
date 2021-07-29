// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int findMaxLen(string s)
    {

        stack<int> s1;
        s1.push(-1);
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                s1.push(i);
            else
            {
                s1.pop();
                if (!s1.empty())
                {
                    res = max(i - s1.top(), res);
                }
                else
                {
                    s1.push(i);
                }
            }
        }
        return res;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
// } Driver Code Ends