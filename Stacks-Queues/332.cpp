// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        string s = "";
        queue<char> q;
        int arr[26] = {0};
        for (int i = 0; i < A.size(); i++)
        {

            q.push(A[i]);
            arr[A[i] - 'a']++;
            while (!q.empty())
            {
                if (arr[q.front() - 'a'] > 1)
                {
                    q.pop();
                }
                else
                    break;
            }
            if (q.empty())
                s += '#';
            else
                s += q.front();
        }

        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends