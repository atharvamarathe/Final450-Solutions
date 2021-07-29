// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
#define GETLCHILD(i) (2 * i + 1)
#define GETRCHILD(i) (2 * i + 2)
#define GETPARENT(i) ((i - 1) / 2)
    void swap(vector<int> &arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    void heapify(vector<int> &arr, int i)
    {
        int largest = i;
        int temp;
        int lchild = GETLCHILD(i);
        int rchild = GETRCHILD(i);
        if (lchild < arr.size())
        {
            if (arr[lchild] > arr[largest])
            {
                largest = lchild;
            }
        }
        if (rchild < arr.size())
        {
            if (arr[rchild] > arr[largest])
            {
                largest = rchild;
            }
        }
        if (largest != i)
        {
            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> arr = a;
        for (int i = 0; i < b.size(); i++)
        {
            arr.push_back(b[i]);
        }
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
        {
            // printf("THe element is bsdj %d\n",arr[i]);
            heapify(arr, i);
        }
        return arr;
        // your code here
    }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged)
{
    if (arr1.size() + arr2.size() != merged.size())
    {
        return false;
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    sort(arr1.begin(), arr1.end());
    vector<int> mergedCopy = merged;
    sort(mergedCopy.begin(), mergedCopy.end());
    if (arr1 != mergedCopy)
    {
        return false;
    }
    for (int i = 1; i < merged.size(); i++)
    {
        if (merged[i] > merged[(i - 1) / 2])
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n, 0), b(m, 0);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if (flag == false)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
// } Driver Code Ends