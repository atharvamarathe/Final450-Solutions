// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int N)
    {
        int *res = new int(2);

        for (int i = 0; i < N; i++)
        {
            arr[i] -= 1;
        }

        for (int i = 0; i < N; i++)
        {
            arr[arr[i] % N] += N;
        }

        for (int i = 0; i < N; i++)
        {
            arr[i] /= N;

            if (arr[i] == 2)
            {
                res[0] = i + 1;
            }

            if (arr[i] == 0)
            {
                res[1] = i + 1;
            }
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends