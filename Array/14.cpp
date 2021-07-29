class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
       vector<vector<int>>answer;
        vector<int>ans;
        
        int fnum,snum; 
        sort(intervals.begin(),intervals.end()); 

        for(int i=0;i<intervals.size();i++){
          fnum=intervals[i][0];   
          snum=intervals[i][1];  
            
          while(i+1<intervals.size()&&snum>=intervals[i+1][0]) { 
            i++;
            snum=max(snum,intervals[i][1]); 
          }
            
          ans.push_back(fnum);
          ans.push_back(snum);
          answer.push_back(ans);
          ans.clear();
        }
        return answer;
        
    }
};