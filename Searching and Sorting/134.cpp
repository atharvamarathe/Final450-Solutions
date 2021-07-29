#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long int merge(long long arr[], long long int left, long long int mid, long long int right)
    {
        long long int lindex = mid - left + 1;
        long long int rindex = right - mid;
        long long int res = 0;
        auto *leftArray = new long long int[lindex];
        auto *rightArray = new long long int[rindex];
        for (auto i = 0; i < lindex; i++)
        {
            leftArray[i] = arr[left + i];
        }
        for (auto j = 0; j < rindex; j++)
        {
            rightArray[j] = arr[mid + 1 + j];
        }

        long long int i = 0, j = 0, k = left;
        while (i < lindex && j < rindex)
        {
            if (leftArray[i] <= rightArray[j])
            {
                arr[k++] = leftArray[i++];
            }
            else
            {
                arr[k++] = rightArray[j++];
                res += (lindex - i);
            }
        }
        while (i < lindex)
        {
            arr[k++] = leftArray[i++];
        }
        while (j < rindex)
        {
            arr[k++] = rightArray[j++];
        }
        return res;
    }
    long long int mergeSort(long long arr[], long long low, long long high)
    {
        long long res = 0;
        if (low >= high)
            return res;
        long long int mid = low + (high - low) / 2;
        res += mergeSort(arr, low, mid);
        res += mergeSort(arr, mid + 1, high);
        res += merge(arr, low, mid, high);
        return res;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code
        return mergeSort(arr, 0, N - 1);
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends