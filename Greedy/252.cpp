#include <iostream>
#include <bits/stdc++.h>


using namespace std;



int maximumProductSubArray(int arr[],int n) {

    int prod=1;
    int count_neg=0;
    int count_zeros = 0;
    int max_neg = INT_MIN;
    for(int i = 0;i<n;i++) {
        if(arr[i] == 0) {
            count_zeros +=1;
        }
        else {
            if(arr[i] < 0) {
                if(max_neg < arr[i])
                    max_neg = arr[i];
                count_neg +=1;
            }
            prod *= arr[i];
        }
    }

    if(count_zero == n)
        return 0;
    if(count_neg & 1) {
        if(count_neg == 1 && count_zeros > 0)
            return 0;
        prod /= max_neg;
    }

    return prod;
}


int main() {
    int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maximumProductSubArray(a, n);
    return 0;
}