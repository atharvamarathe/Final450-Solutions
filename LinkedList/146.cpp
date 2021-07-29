#include <iostream>

using namespace std;

typedef struct node{

    int data;
    struct node *next;
}Node;

Node* MoveLastElement(Node* head) {

    if(head == NULL)
        return head;
    Node *curr = head;
    Node *temp;
    while(curr -> next != NULL) {
        temp = curr;
        curr = curr -> next;
    }
    curr -> next = head;
    temp -> next = NULL;
    return curr;
}



int main() {

    Node* head = (Node*)malloc(sizeof(Node));
    head -> data = 1;
    head ->next = (Node*)malloc(sizeof(Node));
    head -> next -> data = 2;
    head -> next -> next = (Node*)malloc(sizeof(Node));
    head -> next -> next -> data = 3;
    head -> next -> next -> next= (Node*)malloc(sizeof(Node));
    head -> next -> next -> next -> data = 4;
    head -> next -> next -> next -> next = NULL;
    head = MoveLastElement(head);

    Node* curr = head;
    while(curr != NULL) {
        printf("%d ",curr -> data);
        curr = curr -> next;
    }
    printf("\n");
    return 0;

}