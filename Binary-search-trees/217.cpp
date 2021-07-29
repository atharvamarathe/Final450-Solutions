// { Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
#include<vector>
typedef struct temp{
    Node* node;
    int key;
}temp;
void inorder(Node* root,vector<temp>& ans) {
        if(root == NULL)
            return;
        inorder(root->left,ans);
        temp a;
        a.node = root;
        a.key = root ->key;
        ans.push_back(a);
        inorder(root->right,ans);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    vector<temp>ans;
    inorder(root,ans);
    int i =0;
    while(i < ans.size() && (ans.at(i)).key < key) {
        i++;
    }
    if(i == ans.size()) {
        pre = ans.at(i-1).node;
        return;
    }
    else {
        // if(i >= ans.size() || i-1 < 0)
            // cout << "-1";
            
         if( i-1 >= 0)
            pre = (ans.at(i-1)).node;
        // else 
        //     cout << "-1 ";
        if(ans.at(i).key != key && i < ans.size()) 
            suc = (ans.at(i)).node;
        else if(ans.at(i).key == key && i+1< ans.size())
            suc = (ans.at(i+1)).node;
        // else
        //     cout << "-1 ";
       
            
    }
// Your code goes here

}