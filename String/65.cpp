// CPP rogram to print all subsequence of a
// given string.
#include <bits/stdc++.h>
using namespace std;

// set to store all the subsequences
unordered_set<string> st;

// Function computes all the subsequence of an string
void subsequence(string str)
{

    // Iterate over the entire string
    for (int i = 0; i < str.length(); i++)
    {

        // Iterate from the end of the string
        // to generate substrings
        for (int j = str.length(); j > i; j--)
        {
            string sub_str = str.substr(i, j);
            st.insert(sub_str);

            // Drop kth character in the substring
            // and if its not in the set then recur
            for (int k = 1; k < sub_str.length(); k++)
            {
                string sb = sub_str;

                // Drop character from the string
                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }
}

// Driver Code
int main()
{
    string s = "aabc";
    subsequence(s);
    for (auto i : st)
        cout << i << " ";
    cout << endl;

    return 0;
}

// This code is contributed by
// sanjeev2552
