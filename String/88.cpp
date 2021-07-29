// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string findSubString(string str)
    {
        unordered_map<char, int> m;
        for (auto c : str)
        {
            m.insert(pair<char, int>(c, 0));
        }
        int start = 0;
        int end = 0;
        int min_size = INT_MAX;
        int count = 0;
        while (end != str.size())
        {
            char c = str[end];
            if (m[c] == 0)
                count++;
            m[c] += 1;
            if (count == m.size())
            {
                while ((m[str[start]] - 1) > 0)
                {
                    m[str[start]] -= 1;
                    start++;
                }
                if (min_size > (end - start + 1))
                {
                    min_size = end - start + 1;
                }
            }
            end++;
        }

        return str.substr(start, min_size);
        // Your code goes here
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
} // } Driver Code Ends