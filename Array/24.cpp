// { Driver Code Starts


//   O(n) Solution with O(n) space Complexity using hash tables

// // C++ program to find longest
// // contiguous subsequence
// #include <bits/stdc++.h>
// using namespace std;

// // Returns length of the longest
// // contiguous subsequence
// int findLongestConseqSubseq(int arr[], int n)
// {
//     unordered_set<int> S;
//     int ans = 0;

//     // Hash all the array elements
//     for (int i = 0; i < n; i++)
//         S.insert(arr[i]);

//     // check each possible sequence from
//     // the start then update optimal length
//     for (int i = 0; i < n; i++)
//     {
//         // if current element is the starting
//         // element of a sequence
//         if (S.find(arr[i] - 1) == S.end())
//         {
//             // Then check for next elements
//             // in the sequence
//             int j = arr[i];
//             while (S.find(j) != S.end())
//                 j++;

//             // update  optimal length if
//             // this length is more
//             ans = max(ans, j - arr[i]);
//         }
//     }
//     return ans;
// }

// // Driver code
// int main()
// {
//     int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
//     int n = sizeof arr / sizeof arr[0];
//     cout << "Length of the Longest contiguous subsequence "
//             "is "
//          << findLongestConseqSubseq(arr, n);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr,arr+N);
        int count=0;
        int maxcount=0;
        int i =0;
        while(i < N-1) {
            if(arr[i+1] == arr[i]+1)
                count++;
            else if(arr[i+1] > arr[i] + 1)
                count=0;
            i++;
            maxcount= max(maxcount,count);
        }
        
        return maxcount+1;
      //Your code here
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
