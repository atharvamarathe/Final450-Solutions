#include <iostream>

using namespace std;

bool isValidshuffle(string a, string b, string result)
{

    if (a.length() + b.length() != result.length())
    {
        return false;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(result.begin(), result.end());

    int i = 0, j = 0, k = 0;

    while (k < result.length())
    {
        if (i < a.length() && a[i] == result[k])
        {
            i++;
        }
        else if (j < b.length() && b[i] == result[k])
        {
            j++;
        }
        else
            return false;
        k++;
    }

    return true;
}