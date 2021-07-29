// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node* reverseList(struct node* root,int k) {
        struct node *prev = NULL;
        struct node *curr = root;
        if(root == NULL)
            return NULL;
        struct node *next = curr -> next;
        
        while(next != NULL && k > 0) {
    
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = curr -> next;
            k-=1;
        }
        curr -> next = prev;
        return curr;
        
    }
    struct node *reverse (struct node *head, int k)
    { 
        struct node *curr = head;
        struct node *prev = NULL;
        struct node *next;
        int n = k;
        while(n-- && curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        if(head != NULL)
            head -> next = reverse(next,k);
        return prev;
        
        
        
        // Complete this method
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends