// { Driver Code Starts

// What you need to know:
// 1) How to find number of trailing zeroes of a factorial without actually finding the factorial
// 2) How to increment left and right pointers to binary search in a infinitely large search space

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int count(int n)
    {
        if (n < 5)
            return 0;
        return n / 5 + count(n / 5);
    }
    int findNum(int n)
    {
        int l = 0;
        int r = 50000;
        int ans = 500000;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (count(mid) >= n)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans;
        //complete the function here
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
        Solution ob;
        cout << ob.findNum(n) << endl;
    }
    return 0;
} // } Driver Code Ends