// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node *head)
    {
        
        Node *prev = NULL;
        Node *curr = head;
        if(head == NULL)
            return NULL;
        Node *next = curr -> next;
        
        while(next != NULL) {
    
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = curr -> next;
        }
        curr -> next = prev;
        return curr;
        // code here
        // return head of reversed list
    }
    Node* addOne(Node *head) 
    {
        
        head = reverseList(head);
        Node* curr = head;
        int carry = 1;
        while(curr ->next!= NULL) {
            if(curr -> data == 9 && carry == 1) {
                curr -> data = 0;
                carry = 1;
            }
            
            else {
                curr -> data += carry;
                carry = 0;
            }
            curr = curr -> next;
        }
        
        if(curr -> data == 9 && carry == 1) {
            curr -> data = 0;
            curr -> next = (Node*)malloc(sizeof(Node));
            curr -> next -> data = 1;
            curr -> next -> next = NULL;
        }
        else {
            curr -> data +=carry;
        }
        
        return reverseList(head);
        // Your Code here
        // return head of list after adding one
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends