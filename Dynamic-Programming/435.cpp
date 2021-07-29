// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        int sum = 0;
        int i = N - 1, j = N - 2;
        while (i >= 0 && j >= 0)
        {
            if (arr[i] - arr[j] < K)
            {
                sum += arr[i] + arr[j];
                i = j - 1;
                j = i - 1;
            }
            else
            {
                i = j;
                j = i - 1;
            }
        }
        return sum;
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
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        int K;
        cin >> K;
        Solution ob;
        cout << ob.maxSumPairWithDifferenceLessThanK(arr, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends