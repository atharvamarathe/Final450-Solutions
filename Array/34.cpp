// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends


/*Complete the function below*/
bool isPalindrome(int a) {
    int temp =a;
    int buf = 0;
    while(a>0) {
        buf = buf*10 + a%10;
        a = a/10;
    }
    if(temp == buf)
        return true;
    return false;
}
int PalinArray(int a[], int n)
{
    for(int i = 0;i<n;i++) {
        if(!isPalindrome(a[i]))
            return 0;
    }
    return 1;
    //add code here.
}