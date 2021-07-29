#include <iostream>
#include <bits/stdc++.h>


using namespace std;



void maxMeetings(int S[],int F[],int N) {
    vector<int>ans;
    vector<pair<int,int>>v;
    for(int i =0;i<N;i++) {
        v.push_back(make_pair(F[i],S[i]));
    }
    sort(v.begin(),v.end());
    int temp = v[0].first;
    ans.push_back(1);
    for(int i = 1; i < N ;i++) {
        if(temp <= v[i].second) {
            ans.push_back(i+1);
            temp = v[i].first;
        }
    }

    for(int i = 0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    int f[] = { 2, 4, 6, 7, 9, 9 };
     
    int n = sizeof(s) / sizeof(s[0]);
 
    maxMeetings(s, f, n);
 
    return 0;
}