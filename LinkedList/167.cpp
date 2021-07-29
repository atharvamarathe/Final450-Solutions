// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        if (!head)
            return head;
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        Node *temp = head;
        while (temp)
        {
            if (temp->data == 0)
                count_0++;
            else if (temp->data == 1)
                count_1++;
            else
                count_2++;
            temp = temp->next;
        }
        temp = head;
        while (count_0)
        {
            temp->data = 0;
            temp = temp->next;
            count_0--;
        }
        while (count_1)
        {
            temp->data = 1;
            temp = temp->next;
            count_1--;
        }
        while (count_2)
        {
            temp->data = 2;
            temp = temp->next;
            count_2--;
        }

        return head;
        // Add code here
    }
};

// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
} // } Driver Code Ends