// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* merge(Node* l1,Node* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1 -> data < l2 -> data) {
            l1 -> next = merge(l2,l1 -> next);
            return l1;
        }
        else {
            l2 -> next = merge(l1,l2 -> next);
            return l2;
        }
        
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        Node* slow = head;
        Node* fast = head -> next;
        // int count = 0;
        while(fast && fast-> next)  {
            fast = fast ->next -> next;
            slow = slow -> next;
            // count++;
        }
        
        Node* newList = slow -> next;
        slow -> next = NULL;
        
        return merge(mergeSort(head),mergeSort(newList));
        
        
        // your code here
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends