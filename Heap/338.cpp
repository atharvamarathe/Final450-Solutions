// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    void deleteEle(priority_queue<int> &pq, int a)
    {
        priority_queue<int> temp;
        while (pq.top() != a)
        {
            temp.push(pq.top());
            pq.pop();
        }
        pq.pop();
        while (!temp.empty())
        {
            pq.push(temp.top());
            temp.pop();
        }
        return;
    }
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<int> pq;
        vector<int> ans;
        for (int i = 0; i < min(n, k); i++)
        {
            pq.push(arr[i]);
        }
        ans.push_back(pq.top());
        deleteEle(pq, arr[0]);
        for (int i = 0; i < n - k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                pq.push(arr[1 + i + j]);
            }
            ans.push_back(pq.top());
            deleteEle(pq, arr[1 + i]);
        }
        return ans;
        // your code here
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends