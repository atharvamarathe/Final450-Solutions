#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        
        int aIndex = 0;  
        int bIndex = 0;  
        
        int previous = 0;           
        int current = 0;           
        int resultIndex = 0;      
        
        while(resultIndex++ <= (len / 2)) {    
            
            previous = current;          

            if(aIndex >= nums1.size()) {    
                current = nums2[bIndex++];   
                continue;                
            } 
            
            if(bIndex >= nums2.size() ) {    
                current = nums1[aIndex++];
                continue;
            } 
            
            if(nums1[aIndex] < nums2[bIndex]) {  
                current = nums1[aIndex++];
            } else {
                current = nums2[bIndex++];
            }
        }
        
        if(len % 2 == 0) {   
            return (double) (previous  + current)/2;   
        } else {
            return (double) current;                  
        }
    }
};