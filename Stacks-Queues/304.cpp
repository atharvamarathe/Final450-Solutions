// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> ans;
        ans.push_back(-1);
        stack<long long> s1;
        s1.push(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!s1.empty() && s1.top() < arr[i])
            {
                s1.pop();
            }
            if (s1.empty())
            {
                ans.push_back(-1);
                s1.push(arr[i]);
            }
            else
            {
                ans.push_back(s1.top());
                s1.push(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        // Your code here
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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends