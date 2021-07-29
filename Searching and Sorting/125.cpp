// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    bool isValid(int arr[], int n, int k, int max)
    {
        int students = 1;
        int sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            sum += arr[i];
            if (sum > max)
            {
                sum = arr[i];
                students++;
            }
            if (students > k)
                return false;
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int k)
    {
        if (k > n)
            return -1;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            start = max(start, arr[i]);
            end += arr[i];
        }
        int res = -1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (isValid(arr, n, k, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return res;

        //code here
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends