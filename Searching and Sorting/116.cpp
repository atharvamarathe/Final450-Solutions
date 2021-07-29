// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        long long int product = 1;
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeroCount++;
        }
        if (zeroCount == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                product *= nums[i];
            }
            vector<long long int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                ans.push_back(product / nums[i]);
            }
            return ans;
        }
        else if (zeroCount == 1)
        {
            int zeroIdx = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    zeroIdx = i;
                    continue;
                }
                product *= nums[i];
            }
            vector<long long int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i == zeroIdx)
                {
                    ans.push_back(product);
                    continue;
                }
                ans.push_back(0);
            }
            return ans;
        }

        else
        {
            vector<long long int> ans(nums.size(), 0);
            return ans;
        }

        //   return ans;
        //code here
    }
};

// { Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends