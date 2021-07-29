#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());
    stack<pair<int, int>> s1;
    s1.push({intervals[0][0], intervals[0][1]});
    for (int i = 1; i < intervals.size(); i++)
    {
        if (s1.top().second > intervals[i].first)
        {
            pair<int, int> temp = s1.top();
            s1.pop();
            temp.first = min(temp.first, intervals.first);
            temp.second = max(temp.second, intervals.second);
            s1.push(temp);
        }
        else
        {
            s1.push({intervals[i][0], intervals[i][1]});
        }
    }
    vector<vector<int>> res;
    for (int i = 0; i < s1.size(); i++)
    {
        res.push_back({s1.top().first, s1.top().second});
        s1.pop();
    }
    return res;
}