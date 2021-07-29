// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    int f1 = 0;
    int f2 = 0;
    for(int i=0;i<S.length();i++) {
        if(i%2 == S[i] - '0')
            f1++;
        else 
            f2++;
    }
    return min(f1,f2);
    // your code here
}