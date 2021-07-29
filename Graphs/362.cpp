// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    bool isValid(int a,int b,int N) {
        if(a > 0 && a <=N && b > 0 && b <= N)
            return true;
        return false;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<bool>> visited(N,vector<bool>(N,false));
	    queue<pair<int,int>> q1;
	    q1.push(make_pair(KnightPos[0],KnightPos[1]));
	    vector<int>dx = {-2,-1,1,2,2,1,-1,-2};
	    vector<int>dy = {1,2,2,1,-1,-2,-2,-1};
	    int steps = 0;
	    visited[q1.front().first-1][q1.front().second-1] = true;
	    while(!q1.empty()) {
	        
	        int n = q1.size();
	        for(int i = 0;i<n;i++) {
	            pair<int,int>temp = q1.front();
	            q1.pop();
	            if(temp.first == TargetPos[0] && temp.second == TargetPos[1])
	                return steps;
	            for(int i = 0;i<8;i++) {
	                int r = temp.first +dx[i];
	                int c = temp.second + dy[i];
	                if(isValid(r,c,N) && !visited[r-1][c-1]) {
	                    
	                    visited[r-1][c-1] = true;
	                    q1.push(make_pair(r,c));
	                }
	            }
	       
	        }
	        
	        steps+=1;
	    }
	    
	    return -1;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends