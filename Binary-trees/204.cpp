#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};
  
int sumOfTree(Node* root) {
        if(root == NULL)
            return 0;
        else 
            return root -> data + sumOfTree(root -> left) + sumOfTree(root -> right);
    }

int maxSum = 0;
void LargestSubTreeSum(Node* root) {

    if(root == NULL)
        return ;
    int rootSum = sumOfTree(root);
    if(rootSum > maxSum)
        maxSum = rootSum;
    int leftSum = sumOfTree(root -> left);
    if(leftSum > maxSum)
        maxSum = leftSum;
    int rightSum = sumOfTree(root -> right);
    if(rightSum > maxSum)
        maxSum = rightSum;
}

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
  
    LargestSubTreeSum(root);
    cout << maxSum<<endl;
    
    return 0;

}