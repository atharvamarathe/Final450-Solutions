#include <iostream>
#include <bits/stdc++.h>


using namespace std;



int smallestSubsetSum(int arr[],int n) {

    sort(arr,arr+n);
    int count = 0;
    int sum = 0,sum1 = 0;
    for(int i = 0;i<n;i++) {
        sum+=arr[i];
    }
    for(int i =n-1;i>=0;i--) {
        sum1 += arr[i];
        count +=1;
        if(sum1 > sum /2)
            return count;
    }

    return count;
}


int main()
{
    int arr[] = {3, 1, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << smallestSubsetSum(arr, n) << endl;
    return 0;
}