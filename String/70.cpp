// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void reverseUtil(vector<int>&arr,int i) {
        for(int j = i;j<(arr.size()-i)/2;j++) {
            
        }
    }
    vector<int> nextPermutation(int N, vector<int> nums){
         vector<int>::iterator it;
        if(nums.size() ==1)
            return nums;
        for(it = (nums.end()-1);it > nums.begin();it--) {
            if(*it > *(it-1))
                break;
        }
        if((it) == nums.begin()) {
            sort(nums.begin(),nums.end());
        }
        else {
            int temp = *(it-1);
            vector<int>::iterator temp1 = it;
            for(auto i = (it);i!=nums.end();i++) {
                if(*i>temp && *i <= *temp1){
                    temp1 = i;
                    // break;
                }
            }
        *(it-1) = *temp1;
        *temp1 = temp;
        sort(it,nums.end());
            
        }
        return nums;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends