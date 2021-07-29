// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string solve(int arr[], int n)
    {
        sort(arr, arr + n);
        string ans;
        int carry = 0;
        int i;
        for (i = n - 1; (i - 1) >= 0;)
        {
            int curr = arr[i] + arr[i - 1] + carry;
            carry = curr / 10;
            curr = curr % 10;
            ans = to_string(curr) + ans;
            i -= 2;
        }
        int val = 0;
        if (i == 0)
        {
            val += arr[0];
        }
        val += carry;
        ans = to_string(carry + arr[i]) + ans;
        i = 0;
        while (ans[i] == '0')
            i++;
        return ans.substr(i);
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends