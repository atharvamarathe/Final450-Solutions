// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool flag;
    void solve(int arr[],int i,int n,int k,int subsetsum[],int ssf){
        if(i==n){
            if(ssf==k){ 
                int b=1;
                for(int j=0;j<k-1;j++){
                    if(subsetsum[j]!=subsetsum[j+1]){
                        b=0;
                        break;
                    }
                }
                if(b) flag=true;
            }     
            return;
        }
        for(int j=0;j<k;j++){
            if(subsetsum[j]>0){
                subsetsum[j]+=arr[i];
                solve(arr,i+1,n,k,subsetsum,ssf);
                subsetsum[j]-=arr[i];
            }
            else{
                subsetsum[j]+=arr[i];
                solve(arr,i+1,n,k,subsetsum,ssf+1);
                subsetsum[j]-=arr[i];
                break;
            }
        }
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum =0;
        for(int i=0;i<n;i++) {
            sum +=a[i];
        }
        if(k==1)
            return true;
        else if (k > n || sum%k != 0)
            return false;
        else {
            flag = false;
            int subsetsum[k] = {0};
            solve(a,0,n,k,subsetsum,0);
            return flag;
        } 
            
         //Your code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends