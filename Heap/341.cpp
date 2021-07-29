// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    typedef pair<int, pair<int, int>> pq;
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        priority_queue<pq, vector<pq>, greater<pq>> q;
        for (int i = 0; i < K; i++)
        {
            q.push(make_pair(arr[i][0], make_pair(i, 0)));
        }
        int j = 0;
        while (!q.empty())
        {

            pq curr = q.top();
            q.pop();
            res.push_back(curr.first);
            int iarr = curr.second.first;
            int iele = curr.second.second;
            if (iele < K - 1)
            {
                q.push(make_pair(arr[iarr][iele + 1], make_pair(iarr, iele + 1)));
            }
        }
        return res;
        //code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends