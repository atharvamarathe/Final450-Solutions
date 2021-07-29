// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool checkKthBitSet(int n, int k)
    {
        int i = 1;
        while (i < k)
        {
            n >>= 1;
            i++;
        }

        return n & 1;
    }
    vector<int> singleNumber(vector<int> a)
    {
        int n = a.size();
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x ^= a[i];
        }
        vector<int> ans(2);

        int rm = log2(x & (-x)) + 1;
        int b = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (checkKthBitSet(a[i], rm))
            {
                b ^= a[i];
            }
            else
            {
                c ^= a[i];
            }
        }

        ans[0] = min(b, c);
        ans[1] = max(b, c);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends