// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int directionX[8] = {0,0,1,-1,1,-1,1,-1};
    int directionY[8] = {1,-1,0,0,1,-1,-1,1};
    void dfs_travel(vector<vector<char>>& grid, int n, int m, vector<vector<bool>> &visited, int startX, int startY) {
        visited[startX][startY] = true;

        for (int i = 0; i < 8; ++i) {
            int destX = startX + directionX[i];
            int destY = startY + directionY[i];
            if (destX < n && destX >= 0 && destY >= 0 && destY < m && !visited[destX][destY] && grid[destX][destY] == '1') {
                dfs_travel(grid, n, m, visited, destX, destY);
            }
        }
    }
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                visited[i][j] = false;
            }
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    answer++;
//call dfs using i,j as a starting point
                    dfs_travel(grid, n, m, visited, i, j);
                }
            }
        }
        return answer;
        
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends