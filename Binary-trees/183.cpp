
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}tree;

void preorder(tree* root) {
    if(root == NULL) 
        return;
    printf("%d ",root -> data);
    preorder(root->left);
    preorder(root->right);
        
}


// { Driver Code Starts
//Initial Template for C++


//Initial Template for C++



// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> inOrder(Node* node);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



vector<int> preOrder(Node* root);

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        
        getline(cin, s);
       
        Node* root = buildTree(s);

        vector<int> ans;
        ans = preOrder(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";

        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/

vector<int> preOrder(Node* root)
{
    vector<int>ans;
    stack<Node*>s1;
    if(root == NULL)
        return ans;
    Node* buf = root;
    while(buf != NULL) {
        
        ans.push_back(buf->data);
        s1.push(buf);
        buf = buf -> left;
    }
    
    Node* temp;
    while(!s1.empty()) {
        temp = s1.top();
        s1.pop();
        temp = temp -> right;
        while(temp != NULL) {
            ans.push_back(temp->data);
            s1.push(temp);
            temp = temp -> left;
        }
    }
    //code here
    return ans;
}