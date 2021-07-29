// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Calculating next gap
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;

    return (int)ceil(gap / 2.0);
}

// Function for swapping
void swap(int nums[], int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// Merging the subarrays using shell sorting
// Time Complexity: O(nlog n)
// Space Complexity: O(1)
void inPlaceMerge(int nums[], int start,
                  int end)
{
    int gap = end - start + 1;

    for (gap = nextGap(gap);
         gap > 0; gap = nextGap(gap))
    {
        for (int i = start; i + gap <= end; i++)
        {
            int j = i + gap;
            if (nums[i] > nums[j])
                swap(nums, i, j);
        }
    }
}

// merge sort makes log n recursive calls
// and each time calls merge()
// which takes nlog n steps
// Time Complexity: O(n*log n + 2((n/2)*log(n/2)) +
// 4((n/4)*log(n/4)) +.....+ 1)
// Time Complexity: O(logn*(n*log n))
// i.e. O(n*(logn)^2)
// Space Complexity: O(1)
void mergeSort(int nums[], int s, int e)
{
    if (s == e)
        return;

    // Calculating mid to slice the
    // array in two halves
    int mid = (s + e) / 2;

    // Recursive calls to sort left
    // and right subarrays
    mergeSort(nums, s, mid);
    mergeSort(nums, mid + 1, e);

    inPlaceMerge(nums, s, e);
}

// Driver Code
int main()
{
    int nums[] = {12, 11, 13, 5, 6, 7};
    int nums_size = sizeof(nums) / sizeof(nums[0]);

    mergeSort(nums, 0, nums_size - 1);

    for (int i = 0; i < nums_size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}

// This code is contributed by adityapande88
