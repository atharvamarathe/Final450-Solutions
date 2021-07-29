// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

void printInorder (struct Node* node)
{
    if (node == NULL)
    return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
    return NULL;

    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));


            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

 // } Driver Code Ends
//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    vector<int> inOrder(Node* root)
    {
        vector<int>ans;
        if(root == NULL) {
            return ans;
        }
        
        stack<Node*>s1;
        Node* buf = root;
        while(buf!= NULL) {
            s1.push(buf);
            buf = buf -> left;
        }
        while(s1.empty() == false) {
            
            Node* temp;
            temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            temp = temp -> right;
            while(temp != NULL) {
                s1.push(temp);
                temp = temp -> left;
                
            }
        }
        return ans;
      // Your code here
    }
    Node* buildBST(vector<Node*>ans,int i ,int j) {
        
        if(i<=j)
            return NULL;
        Node* temp = ans.at(i-j/2);
        temp -> left = NULL;
        temp -> right = NULL;
        temp -> left = buildBST(ans,i,(i-j/2)-1);
        temp -> right = buildBST(ans,(i-j/2)+1,j);
        return temp;
            
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        if(root == NULL)
            return root;
        vector<int>ans;
        ans = inOrder(root);
        sort(ans.begin(),ans.end());
        stack<Node*>s1;
        Node* buf = root;
        int i =0;
        while(buf != NULL) {
            
            s1.push(buf);
            buf = buf -> left;
        }
        while(!s1.empty()) {
            Node *temp;
            temp = s1.top();
            s1.pop();
            temp -> data = ans[i];
            i++;
            temp = temp -> right;
            while(temp != NULL) {
                s1.push(temp);
                temp = temp -> left;
                
            }
        }
        
        return root;
        //Your code goes here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends