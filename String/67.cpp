#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxSubStr(string str, int n)
{
    int ans = 0;
    int count_0 = 0;
    int count_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
            count_0++;
        else
        {
            count_1++;
        }
        if (count_0 == count_1)
            ans++;
    }

    return (ans == 0) ? -1 : ans;
}

int main()
{
    string str = "0100110101";
    int n = str.length();

    cout << maxSubStr(str, n);

    return 0;
}