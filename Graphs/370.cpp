#include <iostream> 
#include <vector>
#include <queue>


using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>visited(numCourses,false);
        vector<int>adj[numCourses];
        for(int i = 0;i<prerequisites.size();i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
                
        vector<int> inDegree(numCourses,0);
	   for(int i = 0;i<numCourses;i++) {
	       for(auto v:adj[i]) {
	           inDegree[v]+=1;
	       }
	   }
	   queue<int> q;
	   for(int i =0;i<numCourses;i++) {
	       if(inDegree[i] == 0)
	            q.push(i);
	   }
	   int temp;
	   while(!q.empty()) {
	       temp = q.front();
           visited[temp] = true;
	       q.pop();
	       for(int i = 0;i<adj[temp].size();i++) {
	           if(--inDegree[adj[temp].at(i)] == 0)
	                q.push(adj[temp].at(i));
	       }
	       
	     
	   }
       for(int i = 0;i<visited.size();i++) {
           if(!visited[i])
                return false;
       }
        
        return true;
    }
};