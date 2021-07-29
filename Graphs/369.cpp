// Alternative Topological sort : https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

#include <iostream>
#include <vector>


using namespace std;

vector<int> JobTime(int V, vector<int> adj[]) {
    int time = 1;
    vector<int>ans(V,0);
    vector<int> inDegree(V,0);
	   for(int i = 0;i<V;i++) {
	       for(auto v:adj[i]) {
	           inDegree[v]+=1;
	       }
	   }
	   queue<int> q;
	   for(int i =0;i<V;i++) {
	       if(inDegree[i] == 0) {
                ans[i] = time;
	            q.push(i);
           }
	   }
	   int count = 0;
	   int temp;
	   while(!q.empty()) {
	       temp = q.front();
	       q.pop();
           time++;
	       for(int i = 0;i<adj[temp].size();i++) {
	           if(--inDegree[adj[temp].at(i)] == 0) {
	                q.push(adj[temp].at(i));
                    ans[i] = time;
               }
	       }
	       
	    //    count +=1;
	   }

    return ans;
    
}
    
