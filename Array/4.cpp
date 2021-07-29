// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int zeroptr=0,twoptr=n-1,mid = 0;
        int temp;
        while(mid <= twoptr) {
            if(a[mid] == 0) {
                temp = a[zeroptr];
                a[zeroptr] = a[mid];
                a[mid] = temp;
                zeroptr +=1;
                mid+=1;
            }
            else if(a[mid] == 1)
                mid+=1;
            else if(a[mid] == 2) {
                temp = a[mid];
                a[mid] = a[twoptr];
                a[twoptr] = temp;
                twoptr-=1;
            }
        }
       
        
        // coode here 
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends