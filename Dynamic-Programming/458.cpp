// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n)
{
    vector<vector<long long>> opt(n, vector<long long>(n, 0));
    for (int k = 0; k < n; k++)
        for (int i = 0, j = k; i < n && j < n; i++, j++)
            if (i == j)
                opt[i][j] = arr[i];
            else if (i + 1 == j)
                opt[i][j] = max(arr[i], arr[j]);
            else if (opt[i + 1][j] < opt[i][j - 1])
                opt[i][j] = arr[i] + min(opt[i + 2][j], opt[i + 1][j - 1]);
            else
                opt[i][j] = arr[j] + min(opt[i][j - 2], opt[i + 1][j - 1]);
    return opt[0][n - 1];

    // Your code here
}

// { Driver Code Starts.

int main()
{

    //taking total testcases
    int T;
    cin >> T;
    while (T--)
    {
        //taking number of elements
        int N;
        cin >> N;

        int A[N];

        //inserting the elements
        for (int i = 0; i < N; i++)
            cin >> A[i];

        //calling function maximumAmount()
        cout << maximumAmount(A, N) << endl;
    }
    return 0;
} // } Driver Code Ends