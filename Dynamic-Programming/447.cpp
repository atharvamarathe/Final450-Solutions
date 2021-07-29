// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends

//User function template for C++

// A : given string to search
// B : vector of available strings
int wordBreak(string A, vector<string> &B)
{
    //code here
    vector<int> dp(A.size());

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {

            if (find(B.begin(), B.end(), A.substr(j, i - j + 1)) != B.end())
            {

                if (j > 0)
                    dp[i] += dp[j - 1];

                else
                    dp[i] += 1;
            }
        }
    }

    return dp.back();
}
