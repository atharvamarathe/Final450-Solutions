// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
} // } Driver Code Ends

// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (i + 1 < str.size() && mp[str[i]] < mp[str[i + 1]])
        {
            ans += mp[str[i + 1]] - mp[str[i]];
            i++;
        }
        else
            ans += mp[str[i]];
    }

    return ans;
}