
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}tree;

void postorder(tree* root) {

    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root -> data);
}


// { Driver Code Starts
// Initial Template for C++


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

vector<int> postOrder(Node* root);

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;

        getline(cin, s);

        Node* root = buildTree(s);

        vector<int> ans;
        ans = postOrder(root);

        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

        cout << "\n";

        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
typedef struct pnode{
    Node* node;
    int flag;
}pnode;

vector<int> postOrder(Node* node) {
    
    vector<int>ans;
    stack<pnode>s1;
    if(node == NULL)
        return ans;
    Node* buf = node;
    pnode p;
    while(buf != NULL) {
        p.node = buf;
        p.flag = 0;
        s1.push(p);
        buf = buf -> left;
    }
    Node* temp;
    while(!s1.empty()) {
        
        p = s1.top();
        s1.pop();
        if(p.flag == 0) {
            p.flag = 1;
            temp = p.node;
            s1.push(p);
            temp = temp -> right;
            while(temp != NULL) {
                p.node = temp;
                p.flag = 0;
                s1.push(p);
                temp = temp -> left;
            }
        }
        else {
            temp = p.node;
            ans.push_back(temp->data);
        }
    }
    return ans;
    // code here
}