// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s1;
        for (int i = 0; i < n; i++)
        {
            s1.push(i);
        }
        while (s1.size() >= 2)
        {
            int t1 = s1.top();
            s1.pop();
            int t2 = s1.top();
            s1.pop();
            if (M[t1][t2] == 0)
            {
                s1.push(t1);
            }
            else
                s1.push(t2);
        }
        int ans = s1.top();
        for (int i = 0; i < n; i++)
        {
            if (i != ans)
            {
                if (M[i][ans] == 0 || M[ans][i] == 1)
                    return -1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends