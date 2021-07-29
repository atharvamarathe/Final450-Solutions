#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool compare(Item a,Item b) {
        double i = (double) a.value / a.weight;
        double j = (double) b.value / b.weight;
        
        return (i > j);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,compare);
        double currWeight = 0;
        double profit = 0;
        int left;
        for(int i = 0;i<n;i++) {
            
            if(currWeight + arr[i].weight < W) {
                profit += (double) arr[i].value;
                currWeight += arr[i].weight;
            }
            else {
                left = W - currWeight;
                profit += (double) (arr[i].value * left) / arr[i].weight;
                currWeight += left;
            }
        }
        
        return profit;
        // Your code here 
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends