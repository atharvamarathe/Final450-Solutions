#include <iostream>
#include <vector>
#include <stack>
// Using O(H) extra space only. Not by just ordinary in-order traversal but by some modification of it.

using namespace std;

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
}Node;

Node* FlattenBST(Node* root) {

    if(root == NULL)
        return;
    stack<Node*>s1;
    Node* buf = root;
    while(buf!= NULL) {
        s1.push(buf);
        buf = buf -> left;
    }
    Node* dummy=NULL;
    while(!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        if(dummy == NULL)
            dummy = temp;
        else {

            dummy ->right = temp;
            dummy -> left = NULL;
        } 
        
        temp = temp -> right;
        while(temp != NULL) {
            s1.push(temp);  
            temp = temp -> left;
        }
    }

    return root;
}