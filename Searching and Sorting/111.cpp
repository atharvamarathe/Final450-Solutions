// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int req = k - arr[i] - arr[j];
                int x = j + 1;
                int y = n - 1;
                while (x < y)
                {
                    if (arr[x] + arr[y] < req)
                        x++;
                    else if (arr[x] + arr[y] > req)
                        y--;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[x]);
                        temp.push_back(arr[y]);

                        ans.push_back(temp);
                        x++;
                        y--;
                        while (x < n - 1 && arr[x] == arr[x - 1])
                            x++;
                        while (y > j + 1 && arr[y] == arr[y + 1])
                            y--;
                    }
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends