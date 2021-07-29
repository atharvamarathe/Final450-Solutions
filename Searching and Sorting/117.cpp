// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int a)
    {
        int count = 0;
        while (a > 0)
        {
            a = a & (a - 1);
            count++;
        }
        return count;
    }
    static bool comparator(int a, int b)
    {
        int countA = 0, countB = 0;
        while (a > 0)
        {
            a = a & (a - 1);
            countA++;
        }
        while (b > 0)
        {
            b = b & (b - 1);
            countB++;
        }

        return countA > countB;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, comparator);

        // Your code goes here
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
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends