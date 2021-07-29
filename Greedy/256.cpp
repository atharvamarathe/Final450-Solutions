// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    long long int sum = 0;
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
        sum += (long long int)abs(v[i] - v[i+1]);
    }
    sum += (long long int )abs(v[i] -v[0]);

    return sum;
}