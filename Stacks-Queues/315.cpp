// { Driver Code Starts
//Initial Template for C

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

// Queue is empty when size is 0
int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue *queue, int item)
{
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue.
// It changes front and size
void dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
}

// Function to get front of queue
int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get size of queue
int size(struct Queue *queue)
{
    return queue->size;
}

// } Driver Code Ends
//User function Template for C

/*
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity);

// Queue is empty when size is 0
int isEmpty(struct Queue* queue);
 
// Function to add an item to the queue.
void enqueue(struct Queue* queue, int item);

// Function to remove an item from queue.
void dequeue(struct Queue* queue);
 
// Function to get front of queue
int front(struct Queue* queue);

// Function to get size of queue
int size(struct Queue* queue);
*/

// Function to push an element into stack using two queues.
// 2 Queues q1 and q2 where q1 should be used as stack and q2 as helping queue
// num: number to be inserted
void push(struct Queue *q1, struct Queue *q2, int num)
{
    while (!isEmpty(q1))
    {
        enqueue(q2, front(q1));
        dequeue(q1);
    }
    enqueue(q1, num);
    while (!isEmpty(q2))
    {
        enqueue(q1, front(q2));
        dequeue(q2);
    }

    //code here
}

//Function to pop an element from stack using two queues.
int pop(struct Queue *q1)
{
    if (!isEmpty(q1))
    {
        int temp = front(q1);
        dequeue(q1);
        return temp;
    }
    else
        return -1;
    //code here
}

// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        struct Queue *q1 = createQueue(n);
        struct Queue *q2 = createQueue(n);
        while (n--)
        {
            int opt;
            scanf("%d", &opt);
            if (opt == 1)
            {
                int x;
                scanf("%d", &x);
                push(q1, q2, x);
            }
            else
            {
                printf("%d ", pop(q1));
            }
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends