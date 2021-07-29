#include <iostream>
include <bits.stdc++.h>
#define R 3
#define C 10
using namespace std;

//Code not tested. But logic is correct.

int max1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void longestPathUtil(vector<vector<int>>matrix,int steps,pair<int,int> start,pair<int,int> end,vector<vector<bool>>visited) {
    if(start == end) {
        max1 = max(steps,max1);
        return;
    }
    for(int i =0;i<4;i++) {
        if(matrix[start.first+dx[i]][start.second+dy[i]] && !visited[dx[i]+start.first][dy[i]+start.second]) {
            visited[dx[i]+start.first][dy[i]+start.second] = true;
            longestPathUtil(matrix,steps+1,make_pair(start.first+dx[i],start.second+dy[i]),end,visited);
            visited[dx[i]+start.first][dy[i]+start.second] = false;
        }
    }
    return;
}

int longestPath(vector<vector<int>>matrix,pair<int,int> start,pair<int,int> end) {
    max1 = 0;
    vector<vector<bool>>visited(matrix.size(),vector<bool>(matrix[0].size(),false));
    longestPathUtil(matrix,0,start,end,visited);
    return max1;
}



int main() {
    vector<int> mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
 
    // find longest path with source (0, 0) and
    // destination (1, 7)
    cout << longestPath(mat, make_pair(0, 0), make_pair(1, 7))<<endl;
 
    return 0;
}