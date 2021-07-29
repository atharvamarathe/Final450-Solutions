// { Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
    //Function to reverse a linked list iterative approach
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //RECURSIVE APPROACH
    // struct Node* reverseList(struct Node *head)
    // {
    //     if(head->next == NULL)
    //         return head;
    //     Node* newHead = reverseList(head->next);
    //     head -> next -> next = head;
    //     head -> next = NULL;
    //     return newHead;
    //     // code here
    //     // return head of reversed list
    // }
    struct Node* reverseList(struct Node *head)
    {
        
        struct Node *prev = NULL;
        struct Node *curr = head;
        if(head == NULL)
            return NULL;
        struct Node *next = curr -> next;
        
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
    
};
    


// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends

