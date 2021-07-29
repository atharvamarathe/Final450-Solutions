// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
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
        int largest = i,temp;
        if(lchild < n) {
            if(arr[lchild] > arr[largest]) {
                largest = lchild;
            }
        }
        if(rchild < n) {
            if(arr[rchild] > arr[largest]) {
                largest = rchild;
            }
        }
        if(largest != i) {
            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr,n,largest);
        }
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i = n/2-1 ;i>=0;i--) {
            // printf("THe element is bsdj %d\n",arr[i]);
            heapify(arr,n,i);
        }
        
        // return arr;
    // Your Code Here
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int j = n-1;j>=0;j--) {
            // printf("The element is %d\n",arr[j]);
            swap(arr,0,j);
            heapify(arr,j,0);
        }
        //code here
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends