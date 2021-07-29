// CPP program to find minimum removals
// to make max-min <= K
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

// function to check all possible combinations
// of removal and return the minimum one
int countRemovals(int a[], int i, int j, int k)
{
    // base case when all elements are removed
    if (i >= j)
        return 0;

    // if condition is satisfied, no more
    // removals are required
    else if ((a[j] - a[i]) <= k)
        return 0;

    // if the state has already been visited
    else if (dp[i][j] != -1)
        return dp[i][j];

    // when Amax-Amin>d
    else if ((a[j] - a[i]) > k)
    {

        // minimum is taken of the removal
        // of minimum element or removal
        // of the maximum element
        dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
                           countRemovals(a, i, j - 1, k));
    }
    return dp[i][j];
}

// To sort the array and return the answer
int removals(int a[], int n, int k)
{
    // sort the array
    sort(a, a + n);

    // fill all stated with -1
    // when only one element
    memset(dp, -1, sizeof(dp));
    if (n == 1)
        return 0;
    else
        return countRemovals(a, 0, n - 1, k);
}

// Driver Code
int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
