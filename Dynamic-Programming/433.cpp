// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// -------------------- Similar to acitivity selection problem -------------------------------
struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[], int n)
{
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back({p[i].second, p[i].first});
    }
    sort(res.begin(), res.end());
    int count = 1;
    int end = res[0].first;
    for (int i = 1; i < n; i++)
    {
        if (end < res[i].second)
        {
            count++;
            end = res[i].first;
        }
    }
    return count;

    //Your code here
}

// --------------------------------DYNAMIC PROGRAMMING APPROACH----------------------------------
// CPP program for above approach
// #include <bits/stdc++.h>
// using namespace std;

// // Structure for a Pair
// class Pair
// {
//     public:
//     int a;
//     int b;
// };

// // This function assumes that arr[]
// // is sorted in increasing order
// // according the first
// // (or smaller) values in Pairs.
// int maxChainLength( Pair arr[], int n)
// {
//     int i, j, max = 0;
//     int *mcl = new int[sizeof( int ) * n ];

//     /* Initialize MCL (max chain length)
//     values for all indexes */
//     for ( i = 0; i < n; i++ )
//         mcl[i] = 1;

//     /* Compute optimized chain
//     length values in bottom up manner */
//     for ( i = 1; i < n; i++ )
//         for ( j = 0; j < i; j++ )
//             if ( arr[i].a > arr[j].b &&
//                     mcl[i] < mcl[j] + 1)
//                 mcl[i] = mcl[j] + 1;

//     // mcl[i] now stores the maximum
//     // chain length ending with Pair i

//     /* Pick maximum of all MCL values */
//     for ( i = 0; i < n; i++ )
//         if ( max < mcl[i] )
//             max = mcl[i];

//     /* Free memory to avoid memory leak */

//     return max;
// }

// /* Driver code */
// int main()
// {
//     Pair arr[] = { {5, 24}, {15, 25},
//                         {27, 40}, {50, 60} };
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout << "Length of maximum size chain is "
//                   << maxChainLength( arr, n );
//     return 0;
// }

// // This code is contributed by rathbhupendra
