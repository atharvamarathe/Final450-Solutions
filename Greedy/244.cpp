#include <iostream>
#include <bits/stdc++.h>


using namespace std;

//Code Not tested but similar to GFG article.
//Problem similar to activity selection problem

int MaxTrainsOnPlatforms(int arr[][3],int platforms,int trains) {

    int count = 0;
    vector<pair<int,int>>schedule[platforms];

    for(int i = 0;i<trains;i++) {
        schedule[arr[i][2]-1].push_back(make_pair(arr[i][1],arr[i][1]));
    }

    for(int i = 0;i<platforms;i++) {
    sort(schedule[i].begin(),schedule[i].end());
    }

    for(int i = 0;i<platforms;i++) {

        if(schedule[i].size() == 0)
            continue;
        int x = 0;
        count++;
        for(int j = 1;j<schedule[i].size();j++) {
            if(schedule[i][j].second >= schedule[i][j].first) {
                x = j;
                count++;
            }
        }
    }


    return count;

}