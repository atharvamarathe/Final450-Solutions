// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string toposort(vector<int>adj[],int V) {
        string ans;
        vector<int> inDegree(V,0);
	   for(int i = 0;i<V;i++) {
	       for(auto v:adj[i]) {
	           inDegree[v]+=1;
	       }
	   }
	   queue<int> q;
	   for(int i =0;i<V;i++) {
	       if(inDegree[i] == 0)
	            q.push(i);
	   }
	   int count = 0;
	   int temp;
	   while(!q.empty()) {
	       temp = q.front();
	       ans.push_back(temp+'a');
	       //printf("%d\n",temp+98);
	       q.pop();
	       for(int i = 0;i<adj[temp].size();i++) {
	           if(--inDegree[adj[temp].at(i)] == 0)
	                q.push(adj[temp].at(i));
	       }
	   }
	   
	   return ans;
    }
    string findOrder(string dict[], int N, int K) {
        
        string ans;
        vector<int>adj[K];
        for(int i = 0;i<N-1;i++) {
            int j = 0;
            for(int j = 0;j<min(dict[i].length(),dict[i+1].length());j++) {
                if(dict[i][j] != dict[i+1][j]) {
                    
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        // toposort(adj,K);
        
        return toposort(adj,K);
        //code here
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends