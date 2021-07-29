// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};

    void floodFillUtil(int sr,int sc,int newColor,vector<vector<int>>&image,int replace) {
        if(sc<0||sr<0||sr>=image.size()||sc>=image[0].size()){
            return;
        }
        if(image[sr][sc]==newColor){
            return;
        }
        if(image[sr][sc]!=replace){
            return;
        }
        // int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        for(int i =0;i<4;i++) {
            floodFillUtil(sr+dx[i],sc+dy[i],newColor,image,replace);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        // vector<vector<int>>ans(image);
        floodFillUtil(sr,sc,newColor,image,image[sr][sc]);
        return image;
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends