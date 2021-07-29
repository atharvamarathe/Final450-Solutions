// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long cost = 0;
        for (long long i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        while (!pq.empty())
        {
            long long temp = pq.top();
            pq.pop();
            if (pq.empty())
            {

                return cost;
            }
            long long buf = pq.top();
            pq.pop();
            pq.push(temp + buf);
            cost += temp + buf;
        }
        return cost;
        // Your code here
    }
};

// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends