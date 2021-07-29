// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
// LOGIC CORRECT NOT WORKING CURRENTLY
 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        
        if(S > D*9)
            return "-1"; 
        if(S < 10 && D < 2)
            return to_string(S);
        string ans;
        
        ans = "";
        S = S-1;
        for(int i = 0 ;i< D-1;i++) {
            if(S > 9) {
                printf("9 \n");
                ans += to_string(9);
                cout << "ans is "<<ans<<endl;
                S-=9;
            }
            else {
                // printf("%d\n",S);
                ans += S;
                cout << "ans is "<<ans<<endl;
                S = 0;
            }
        }
        ans += S+1;
        // printf("%d\n",S+1);
        reverse(ans.begin(),ans.end());
        return ans;
        // code here 
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends