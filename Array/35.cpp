#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Approach with O(n) time complexity
int getMedian(int ar1[],int ar2[],int n) {

    int i =0;
    int j = n-1;
    while(ar1[j] > ar2[i] && j>-1 && i<n) {
        int temp = ar1[j];
        ar1[j] = ar2[i];
        ar2[i] = temp;
        j--;
        i++;
    }
    sort(ar1,ar1+n);
    sort(ar2,ar2+n);
    return (ar1[n-1] + ar2[0])/2;
}

// Approach with O(logn) time complexity
int getMedian1(int ar1[],int ar2[],int n) {

    if(n < 1)
        return -1;
    if(n==1) {
        return (ar1[0] + ar1[0])/2;
    }
    if(n==2) {
        return (max(ar1[0],ar2[0])+min(ar1[1],ar2[1]))/2;
    }

    int m1 = median(ar1,n);
    int m2 = median(ar2,n);
    if(m1 == m2) 
        return m1;
    else if(m1 > m2) {
        if(n%2 == 0)
            return getMedian1(ar2 + n/2 - 1, ar1, n - n/2 + 1);
        return getMedian1(ar2 + n/2, ar1, n - n/2);
    }
    else {
        if(n%2 == 0)
            return getMedian1(ar1 + n/2 - 1, ar2, n - n/2 +1);
        return getMedian1(ar1 + n/2, ar2, n - n/2);
    }
}

int median(int arr[],int n) {
    if(n%2==0) {
        return ((arr[n/2]+arr[n/2-1])/2);
    }
    return arr[n/2];
}

int main() {

    int ar1[] = { 1, 12, 15, 26, 38 };
    int ar2[] = { 2, 13, 17, 30, 45 };
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";
    getchar();
    return 0;
}