// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &string_list);

// } Driver Code Ends
//User function Template for C++

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    unordered_map<string, vector<string>> m1;
    vector<vector<string>> ans;
    for (auto i : string_list)
    {
        string temp = i;
        sort(temp.begin(), temp.end());
        m1[temp].push_back(i);
    }
    for (auto i : m1)
    {
        ans.push_back(i.second);
    }

    return ans;
    // Your Code Here
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        vector<vector<string>> result = Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends