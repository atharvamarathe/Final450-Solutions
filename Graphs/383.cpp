#include <iostream>
#include <vector>
#include <queue>

using namespace std;



bool isBiPartite(vector<vector<int>>adj,int V) {

    vector<int> coloured(V,-1);

    coloured[0] = 1;

    queue<int>q1;
    q1.push(0);

    while(!q1.empty()) {
        int temp = q1.top();
        q1.pop();
        if(adj[temp][temp] == 1)
            return false;
        for(int i = 0;i<V;i++) {
            if(adj[temp][i] && colored[i] == -1) {
                coloured[i] = 1- coloured[temp];
                q1.push(i);
            }
            else if(adj[temp][i] && coloured[i] == coloured[temp])
                return false;
        }
    }

    return true;
}