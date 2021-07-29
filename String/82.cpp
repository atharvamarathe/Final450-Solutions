#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];
        string ans;
        int k = 0;
        while (1)
        {
            char temp = strs[0][k];
            for (int i = 1; i < strs.size(); i++)
            {
                if (k == strs[i].length() || temp != strs[i][k])
                    return ans;
            }
            k++;
            ans += temp;
        }
        return ans;
    }
};