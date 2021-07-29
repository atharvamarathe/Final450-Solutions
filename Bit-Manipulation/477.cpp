// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int N)
    {
        // code here
        double temp = log2(N);
        int buf = (int)temp;
        if (temp - (double)buf == 0)
            return (int)temp + 1;
        else
            return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
} // } Driver Code Ends