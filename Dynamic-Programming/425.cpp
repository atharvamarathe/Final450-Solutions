// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int dp[n];
        int omax = 0;
        for (int i = 0; i < n; i++)
        {
            int max1 = 0;
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[i])
                {
                    if (dp[j] > max1)
                        max1 = dp[j];
                }
            }
            dp[i] = max1 + 1;
            if (dp[i] > omax)
                omax = dp[i];
        }
        return omax;
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//  // } Driver Code Ends

// *******************************************ANOTHER SOLUTION ***************************************

// class Solution
// {
//     public:
//     //Function to find length of longest increasing subsequence.
//     int longestSubsequence(int n, int a[])
//     {
//         int dp[n+1];
//       int i,j;
//       dp[1]=a[0];
//       int len=1;
//       int ans=1;
//       for(i=1;i<n;i++)
//         {
//             for(j=len;j>=1;j--)
//                 if(dp[j]<a[i])
//                     break;
//                 if(j==len)
//                  len++;
//                 j++;
//                 dp[j]=a[i];
//                 ans=max(len,ans);
//         }
//     return ans;
//        // your code here
//     }
// };

// // { Driver Code Starts.
// int main()
// {
//     //taking total testcases
//     int t,n;
//     cin>>t;
//     while(t--)
//     {
//         //taking size of array
//         cin>>n;
//         int a[n];

//         //inserting elements to the array
//         for(int i=0;i<n;i++)
//             cin>>a[i];
//         Solution ob;
//         //calling method longestSubsequence()
//         cout << ob.longestSubsequence(n, a) << endl;
//     }
// }
//   // } Driver Code Ends