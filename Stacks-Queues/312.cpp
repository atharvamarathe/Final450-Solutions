// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> lb(n, -1);
        vector<long long> rb(n, -1);
        stack<long long> s1;
        stack<long long> s2;
        s1.push(n - 1);
        s2.push(0);
        lb[0] = -1;
        rb[n - 1] = n;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!s1.empty() && arr[i] < arr[s1.top()])
                s1.pop();
            if (s1.empty())
                rb[i] = n;
            else
            {
                rb[i] = s1.top();
            }
            s1.push(i);
        }
        for (int i = 1; i < n; i++)
        {
            while (!s2.empty() && arr[i] < arr[s2.top()])
                s2.pop();
            if (s2.empty())
                lb[i] = -1;
            else
            {
                lb[i] = s2.top();
            }
            s2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            long long w = rb[i] - lb[i] - 1;
            long long area = w * arr[i];
            res = max(res, area);
        }
        return res;
        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends