// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int minValue(string str, int k)
    {
        int hash[26] = {0};

        for (auto x : str)
        {
            hash[x - 'a']++;
        }

        priority_queue<int> pq;

        for (int i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
            {
                pq.push(hash[i]);
            }
        }

        while (!pq.empty() and k--)
        {
            int freq = pq.top();
            pq.pop();

            pq.push(freq - 1);
        }

        int res = 0;
        while (!pq.empty())
        {
            int freq = pq.top();

            pq.pop();

            res += freq * freq;
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
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
} // } Driver Code Ends