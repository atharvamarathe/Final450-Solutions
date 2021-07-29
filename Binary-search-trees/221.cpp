// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int search(int in[],int a,int size) {
    
    for(int i =0;i<size;i++) {
        if(in[i] == a)
            return i;
    }
}
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        if(n==0)
            return NULL;
        Node *temp = new Node(pre[0]);
        int i = search(in,pre[0],n);
        temp -> left = buildTree(in,pre+1,i);
        temp -> right = buildTree(in+i+1,pre+i+1,n-i-1);
        return temp;
       
        // Code here
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends