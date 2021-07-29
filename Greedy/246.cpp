#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int MaxStocksonIthDay(int price[],int n,int k) {
    vector<pair<int,int>>V;

    for(int i = 0;i<n;i++) {
        V.push_back(make_pair(price[i],i+1));   
    }

    sort(V.begin(),V.end());
    int ans = 0;
    int temp;
    for(int i = 0;i<n;i++) {
        temp = min(V[i].first,k/V[i].first);
        k -= temp*V[i].first;
        ans+=temp;
    }

    return ans;
}


int main()
{
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
  
    cout << MaxStocksonIthDay(price,n, k) << endl;
  
    return 0;
}