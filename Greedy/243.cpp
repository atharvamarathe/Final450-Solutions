// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    
    void replaceAll(string& str,char a,char b) {
        for(int i = 0;i < str.length();i++) {
            if(str[i]== a) {
                
                str[i] = b;
                
            }
            else if(str[i] == b) {
                str[i] = a;
                
            }
        }
        return;
    }
    string chooseandswap(string a){
         
        vector<int>checked(26,-1);
        for(int i = 0;i<a.length();i++) {
            if(checked[a[i]-'a'] == -1)
                checked[a[i]-'a'] = i;
        }
        int i,j;
        for(i = 0;i < a.length(); i++) {
            bool flag = false;
            for(j = 0;j<a[i]-'a';j++) {
                if(checked[j] > checked[a[i] - 'a']) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(i < a.length())
            replaceAll(a,a[i],j+'a');
        return a;
        // Code Here
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends