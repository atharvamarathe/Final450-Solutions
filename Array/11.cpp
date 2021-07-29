#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0];
        int h = nums[0];
        while(1) {
            t = nums[t];
            h = nums[nums[h]];
            if(t == h)
                break;
        }
        t = nums[0];
        while(t != h) {
            t = nums[t];
            h = nums[h];
        }
        return h;
    }
};