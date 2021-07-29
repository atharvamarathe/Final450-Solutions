#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int dis[n];
        fill(dis,dis+n,INT_MAX);
        dis[src] = 0;
        int temp[n];
        for(int i = 0;i<k+1;i++) {
           copy(dis,dis+n,temp);
            for(int j =0;j<flights.size();j++) {
                if(dis[flights[j][0]] == INT_MAX)
                        continue;
                else 
                    temp[flights[j][1]] = min(temp[flights[j][1]],dis[flights[j][0]] + flights[j][2]);
            }
            copy(temp,temp+n,dis);
        }
        return (dis[dst]==INT_MAX) ? -1:dis[dst];
    }
};