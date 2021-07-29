#include <iostream>
#include <vector>
#include <stack>
#include <string>
#define MAX 100
using namespace std;


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;


Node* createBinaryTree(string str) {

    if(str.length() == 0)
        return NULL;
    stack<char>s1;

    Node* root = (Node*)malloc(sizeof(Node));
    root -> left = NULL;
    root -> right = NULL;
    root -> data = str[0] - '0';
    // Node* buf = root;
    int i = 1;
    int temp;
    if(i < str.length()) {
        if(str[i] == '(') {
            temp = i;
            s1.push(str[i]);
            while(s1.empty() == false) {
                i++;
                if(str[i] == ')')
                    s1.pop();
                else if(str[i] == '(')
                    s1.push(str[i]);
            }
            root -> left = createBinaryTree(str.substr(temp+1,i-1));
        }
    }
    i++;
    if(i < str.length()) {
        if(str[i] == '(') {
          temp = i;
          s1.push(str[i]);
        while(s1.empty() == false) {
            i++;
            if(str[i] == ')')
                s1.pop();
            else if(str[i] == '(')
                s1.push(str[i]);
        }
            root -> right = createBinaryTree(str.substr(temp+1,i-1));
        }   
    }

    return root;

}
void inorder(Node* root) {

    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main() {

    string str;
    int n;
    // cout << "Please enter the length of the string :";
    getline(cin, str);
    Node* root = createBinaryTree(str);
    inorder(root);
    return 0;
}