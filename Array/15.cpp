class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator it;
        if(nums.size() ==1)
            return;
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
        
    }
};