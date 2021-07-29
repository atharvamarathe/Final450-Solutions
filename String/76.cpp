// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends

int countRev(string s)
{
    if (s.length() % 2 != 0)
        return -1;
    int count = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
            count++;
        else if (count > 0)
        {
            count--;
        }
        else
        {
            ans++;
            count++;
        }
    }

    return ans + count / 2;
    // your code here
}