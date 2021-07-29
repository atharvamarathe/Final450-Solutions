// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int max1 = INT_MIN, max2 = INT_MIN;
        string resMax1, resMax2;
        for (auto x : mp)
        {
            int freq = x.second;
            if (freq > max1)
            {
                max2 = max1;
                max1 = freq;
                resMax2 = resMax1;
                resMax1 = x.first;
            }
            else if (freq > max2 and freq != max1)
            {
                max2 = freq;
                resMax2 = x.first;
            }
        }
        return resMax2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends