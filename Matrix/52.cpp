// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
// } Driver Code Ends

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < n; i++)
        pq.push(matrix.[i][0], {i, 0});
    int c = k, ans;
    while (c--)
    {
        int a = pq.top().first;
        int b = pq.top().second.first;
        int c = pq.top().second.second;
        ans = a;
        pq.pop();
        if (c != n - 1)
            pq.push({matrix[b][c + 1], {b, c + 1}});
    }
    return ans;

    //Your code here
}
