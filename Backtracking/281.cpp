#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    bool isPalindromic(string s) {
        string str = s;
        reverse(s.begin(),s.end());
        if(str == s)
            return true;
        return false;
    }
    void partitionUtil(string s,vector<string>ans) {
        if(s.length() == 0) {
            res.push_back(ans);
            ans.clear();
            return;
        }
        for(int i =0;i<s.length();i++) {
            string left = s.substr(0,i+1);
            if(isPalindromic(left)) {
                ans.push_back(left);
                partitionUtil(s.substr(i+1),ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        partitionUtil(s,ans);
        return res;
    }
};