// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





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
   Node* root = new Node(stoi(ip[0]));

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

           // Create the left child for the current node
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



/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        stack<Node*>s1,s2;
        Node* buf = root1;
        Node* buf1 = root2;
        while(buf!= NULL) {
            s1.push(buf);
            buf = buf -> left;
        }
        while(buf1!= NULL) {
            s2.push(buf1);
            buf1 = buf1 -> left;
        }
        vector<int>ans;
        int temp = INT_MAX,temp2 = INT_MAX;
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty())
                temp = s1.top()->data;
            else 
                temp = INT_MAX;
            if(!s2.empty())
                temp2 = s2.top()->data;
            else
                temp2 = INT_MAX;
            
            if(temp <= temp2) {
                ans.push_back(temp);
                // s1.pop();
                Node* a = s1.top();
                s1.pop();
                a = a -> right;
                while(a!= NULL) {
                    s1.push(a);
                    a = a -> left;
                }
                
            }
            else {
                ans.push_back(temp2);
                Node* b = s2.top();
                s2.pop();
                b = b ->right;
                while(b!= NULL) {
                    s2.push(b);
                    b = b -> left;
                }
            }
        }
        
        return ans;
        
       //Your code here
    }
};

// { Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends