// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
   
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>ans;
        for(int i =0;i<n;i++) {
            ans.push_back({end[i],start[i]});
        }
        sort(ans.begin(),ans.end());
        int count = 1;
        int curr = ans[0].first;
        for(int i = 1;i<n;i++) {
            if(curr < ans[i].second) {
                count+=1;
                curr = ans[i].first;
            }
        }
        // int st = -1;
        return count;
        // Your code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends