// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    queue<int> q;
    vector<long long> res;

    int si, ei; /*starting index, ending index*/

    for (ei = 0; ei < K; ei++)
        if (A[ei] < 0)
            q.push(A[ei]);

    for (si = 0; ei <= N; si++, ei++)
    {
        res.push_back(q.empty() ? 0 : q.front());
        if (A[si] == q.front())
            q.pop();
        if (A[ei] < 0)
            q.push(A[ei]);
    }

    return res;
}