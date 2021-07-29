// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s1;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '{' || x[i] == '(' || x[i] == '[')
                s1.push(x[i]);
            if (x[i] == '}')
            {
                if (!s1.empty() && s1.top() == '{')
                    s1.pop();
                else
                    return false;
            }
            if (x[i] == ']')
            {
                if (!s1.empty() && s1.top() == '[')
                    s1.pop();
                else
                    return false;
            }
            if (x[i] == ')')
            {
                if (!s1.empty() && s1.top() == '(')
                    s1.pop();
                else
                    return false;
            }
        }
        if (!s1.empty())
            return false;
        return true;

        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends