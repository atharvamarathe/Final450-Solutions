// C++ program for getting minimum character to be
// added at front to make string palindrome

// First we concat string by concatenating given string, a special character and reverse of given string then we
// will get lps array for this concatenated string, recall that each index of lps array represent longest proper
// prefix which is also suffix. We can use this lps array for solving the problem.
//  For string = AACECAAAA
// Concatenated String = AACECAAAA$AAAACECAA
// LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2,
//                    0, 1, 2, 2, 2, 3, 4, 5, 6, 7}

// Here we are only interested in the last value of this lps array because it shows us the largest suffix of the
// reversed string that matches the prefix of the original string i.e these many characters already satisfy the
// palindrome property. Finally minimum number of character needed to make the string a palindrome is length of the
// input string minus last entry of our lps array.

#include <bits/stdc++.h>
using namespace std;

// returns vector lps for given string str
vector<int> computeLPSArray(string str)
{
    int M = str.length();
    vector<int> lps(M);

    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Method returns minimum character to be added at
// front to make string palindrome
int getMinCharToAddedToMakeStringPalin(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    // Get concatenation of string, special character
    // and reverse string
    string concat = str + "$" + revStr;

    // Get LPS array of this concatenated string
    vector<int> lps = computeLPSArray(concat);

    // By subtracting last entry of lps vector from
    // string length, we will get our result
    return (str.length() - lps.back());
}

// Driver program to test above functions
int main()
{
    string str = "AACECAAAA";
    cout << getMinCharToAddedToMakeStringPalin(str);
    return 0;
}
