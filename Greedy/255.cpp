#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int maxSumofDifference(int arr[],int n) {

    sort(arr,arr+n);
    int sum = 0;
    vector<int>v;
    for(int i =0;i<n/2;i++) {
        v.push_back(arr[i]);
        v.push_back(arr[n-i-1]);
    }

    if(n%2 != 0) {
        v.push_back(arr[n/2]);
    }
    int i;
    for(i =0;i<n-1;i++) {
        sum += abs(v[i] - v[i+1]);
    }
    sum += abs(v[i] -v[0]);

    return sum;
}


int main() {


    int a[] = { 1, 2, 4, 8 };
    int n = sizeof(a) / sizeof(a[0]);
 
    cout << maxSumofDifference(a, n) << endl;


    return 0;
}