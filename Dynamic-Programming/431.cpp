#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxSumWO3Consec(int arr[], int n)
{

    int sum[n];
    if (n >= 1)
        sum[0] = arr[0];
    if (n >= 2)
        sum[1] = arr[0] + arr[1];
    if (n > 2)
    {
        sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2]));
    }

    for (int i = 3; i < n; i++)
    {
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]), arr[i] + arr[i - 1] + sum[i - 3]);
    }

    return sum[n - 1];
}

int main()
{

    int arr[] = {100, 1000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}