// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        if (s.length() == 0)
            return "";

        string ans = "";

        char temp = s[0];

        for (int i = 1; i < s.length(); i++)
        {
            if (temp != s[i])
            {
                ans += temp;
            }
            temp = s[i];
        }

        ans += s[s.length() - 1];
        return ans;
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
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends