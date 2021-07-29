// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    string swap(string str,int i,int j) {
        char temp = str[i];
        char temp2 = str[j];
        string left = str.substr(0,i);
        string right = str.substr(j+1);
        string middle = str.substr(i+1,j);
        return left + temp2 + middle + temp + right;
    }
    string res;
    void findMaximumUtil(string str,int k) {
        
        if(stoi(str) > stoi(res))
            res = str;
        if(k==0) {
            return;
        }
        for(int i =0;i<str.length()-1;i++) {
            for(int j = i+1;j<str.length();j++) {
                if(str[j] > str[i]) {
                    string temp = swap(str,i,j);
                    findMaximumUtil(temp,k-1);
                    // swap(str,j,i);
                }
            }
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       res = str;
       findMaximumUtil(str,k);
       return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends