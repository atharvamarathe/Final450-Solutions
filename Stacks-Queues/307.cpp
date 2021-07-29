// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> s1;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                s1.push(S[i] - '0');
            }
            else
            {
                int t1 = s1.top();
                s1.pop();
                int t2 = s1.top();
                s1.pop();
                if (S[i] == '*')
                    s1.push((t1 * t2));
                else if (S[i] == '/')
                    s1.push((int)(t2 / t1));
                else if (S[i] == '+')
                    s1.push((t1 + t2));
                else if (S[i] == '-')
                    s1.push(t2 - t1);
            }
        }
        return s1.top();
        // Your code here
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}
// } Driver Code Ends