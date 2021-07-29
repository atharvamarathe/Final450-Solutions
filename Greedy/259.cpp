// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int pagefaults=0;
        vector<int>memory;
        int i=0;
        // for(i = 0;i<C;i++) {
        //     memory.push_back(pages[i]);
        //     pagefaults++;
        // }
        vector<int>::iterator it;
        while(i<N) {
            it = find(memory.begin(),memory.end(),pages[i]);
            if(it == memory.end()) {
                if(memory.size() ==C)
                    memory.erase(memory.begin());
                memory.push_back(pages[i]);
                pagefaults++;
                i++;
            }
            else {
                memory.erase(it);
                memory.push_back(pages[i]);
                i++;
            }
        }
        
        return pagefaults;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends