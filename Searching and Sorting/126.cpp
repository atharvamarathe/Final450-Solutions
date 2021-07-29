#include <iostream>
using namespace std;

bool isValid(int arr[], int n, int k, int mid)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            sum += (arr[i] - mid);
    }
    if (sum >= k)
        return true;
    else
        return false;
}

int main()
{

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        high = max(high, arr[i]);
    }

    int res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isValid(arr, n, k, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << endl;
    return 0;
}