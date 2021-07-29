#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>arr;
        arr.push_back(0);
        bool inverted = false;
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            if(!inverted){
                inverted = true;
                for(int j=0;j<n;j++){
                    arr.push_back(board[i][j]);
                }
            }
            else{
                inverted = false;
                for(int j=n-1;j>=0;j--){
                    arr.push_back(board[i][j]);
                }
            }
        }
        queue<int>q;
        q.push(1);
        int out=0;
        n=arr.size();
        while(!q.empty()){
            int sz = q.size();
            out++;
            for(int k=0; k<sz; k++) {
                int f=q.front();
                q.pop();
                for(int i=1;i<7;i++){
                    if(arr[f+i] > 0){
                        q.push(arr[f+i]);
                    }
                    else if(arr[f+i] == -1){
                        q.push(f+i);
                    }
                    if(arr[f+i]==n-1 || f+i==n-1){
                        return out;
                    }
                    arr[f+i]=-2;
                }
            }
        }
        return ans;
    }
};