int findPivotIdx(int *nums, int, int, int);
int binarySearch(int *, int, int, int);
int search(int *nums, int numsSize, int target)
{
    int pivotIdx = findPivotIdx(nums, 0, numsSize - 1, nums[0]);
    if (pivotIdx == 0)
    {
        return binarySearch(nums, 0, numsSize - 1, target);
    }
    else if (target == nums[0])
    {
        return 0;
    }
    else if (target > nums[0])
    {
        return binarySearch(nums, 0, pivotIdx - 1, target);
    }
    else
    {
        return binarySearch(nums, pivotIdx, numsSize - 1, target);
    }
}

int findPivotIdx(int *nums, int lowerBound, int upperBound, int pivotValue)
{
    int m = (lowerBound + upperBound) / 2;

    if (lowerBound > upperBound)
    {
        return 0;
    }

    if (lowerBound == upperBound)
    {
        if (nums[m] < pivotValue)
        {
            return m;
        }
        else
        {
            return 0;
        }
    }

    if (nums[m] > pivotValue)
    {
        return findPivotIdx(nums, m + 1, upperBound, pivotValue);
    }
    else if (nums[m] < pivotValue && nums[m] < nums[m - 1])
    {
        return m;
    }
    else if (nums[m] < pivotValue)
    {
        return findPivotIdx(nums, lowerBound, m - 1, pivotValue);
    }
    else
    {
        if (nums[m] > nums[m + 1])
            return findPivotIdx(nums, m + 1, upperBound, pivotValue);
        else
            return 0;
    }
}

int binarySearch(int *nums, int lowerBound, int upperBound, int target)
{
    int m = (lowerBound + upperBound) / 2;

    if (lowerBound > upperBound)
    {
        return -1;
    }

    if (target > nums[m])
    {
        return binarySearch(nums, m + 1, upperBound, target);
    }
    else if (target == nums[m])
    {
        return m;
    }
    else
    {
        return binarySearch(nums, lowerBound, m - 1, target);
    }
}