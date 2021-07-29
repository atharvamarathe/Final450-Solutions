// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
        #define GETLCHILD(i) (2*i+1)
        #define GETRCHILD(i) (2*i+2)
        #define GETPARENT(i) ((i-1)/2)
    
        //Heapify function to maintain heap property.
        void swap(int arr[],int a,int b) {
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
        void heapify(int arr[], int n, int i)  
        {
            int lchild = GETLCHILD(i);
            int rchild = GETRCHILD(i);
            int smallest = i,temp;
            if(lchild < n) {
                if(arr[lchild] < arr[smallest]) {
                    smallest = lchild;
                }
            }
            if(rchild < n) {
                if(arr[rchild] < arr[smallest]) {
                    smallest = rchild;
                }
            }
            if(smallest != i) {
                temp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = temp;
                heapify(arr,n,smallest);
            }
    
        }

        void buildHeap(int arr[], int n)  
        { 
            for(int i = n/2-1 ;i>=0;i--) {
            
                heapify(arr,n,i);
            }
            

        }

        int kthSmallest(int arr[], int l, int r, int k) {
            buildHeap(arr,r+1);

            int i,j;
            for(i =r,j = 0;j<k-1;i--,j++) {

                swap(arr,0,i);
                heapify(arr,i,0);
            }
            
            return arr[0];
        //code here
        }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends