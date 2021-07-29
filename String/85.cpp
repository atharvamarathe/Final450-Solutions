// The trick here is whenever you traverse from left to right, count of left parenthesis will be greater than
// equal to the count of right parenthesis for a balanced state.
// Maintain counters for left and right parenthesis
// Suppose you're going from left to right:-
// If you see a right parenthesis(increment your counter) and you haven't seen any left parenthesis before to
// balance it out, that is, the count of right parenthesis went up than the count of left parenthesis, then there
//  is imbalance.
// Who will remove this imbalance, any left parenthesis which comes ahead.
// So whenever you see a left parenthesis and count of right parenthesis > count of left parenthesis, then there is
// an imbalance and this left parenthesis will help remove / reduce the imbalance. You'll need (count of right - count
// of left) swaps to balance out the first unbalanced right parenthesis you saw, after this you increment the count of
// left parenthesis.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        int countl = 0;
        int countr = 0;
        int ans = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '[')
            {
                if (countr > countl)
                {
                    ans += countr - countl;
                }
                countl++;
            }
            else
                countr++;
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
} // } Driver Code Ends