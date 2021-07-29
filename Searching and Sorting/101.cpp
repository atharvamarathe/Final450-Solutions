// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<int> find(int arr[], int n, int x)
{
    vector<int> res;
    int *a = find(arr, arr + n, x);
    int *i = a;
    int j = i - arr;
    int b = a - arr;
    while (j < n && arr[j] == arr[b])
        j++;
    if (j == n && b == n)
        return {-1, -1};
    res.push_back(b);
    res.push_back(j - 1);
    return res;
    // code here
}