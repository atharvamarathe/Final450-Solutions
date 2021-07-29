#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string>res;

void possiblePathsUtil(vector<vector<int>>matrix,pair<int,int>start,pair<int,int>end,string ans) {
    if(start == end) {
        res.push_back(ans);
        return;
    }
    if(start.first+1 < matrix[0].size()) 
        possiblePathsUtil(matrix,make_pair(start.first+1,start.second),end,ans+'R');
    if(start.second+1 < matrix.size()) 
        possiblePathsUtil(matrix,make_pair(start.first,start.second+1),end,ans+'D');
    return;
}

vector<string> possiblePaths(vector<vector<int>>matrix) {
    string ans;
    possiblePathsUtil(matrix,make_pair(0,0),make_pair(matrix.size()-1,matrix[0].size()),ans);
    return res;
}