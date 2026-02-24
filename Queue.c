// Queue
// FIFO
// stack push   queue enqueue
// stack pop queue dequeue
// stack top    queue--> front , rear
// insert---rear++    delete---> front++
#include <stdio.h>
#include <stdlib.h>
#define MS 5
typedef struct queue
{
    int front;
    int rear;
    int arr[MS];
} queue;
void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}
void push(queue *q, int x)
{
    if (q->rear == MS - 1)
    {
        printf(" Chal nikal yaha se\n");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->front + 1;
        q->rear = q->rear + 1;
    }
    else
    {
        q->rear = q->rear + 1;
    }
    q->arr[q->rear] = x;
}
void display(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
void pop(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf(" Underflow ho gaya hai brother\n");
        return;
    }
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return;
    }
    q->front = q->front + 1;
}
int main()
{
    queue q;
    init(&q);
    push(&q, 10);
    display(&q);
    push(&q, 20);
    display(&q);
    push(&q, 30);
    display(&q);
    push(&q, 40);
    display(&q);
    push(&q, 50);
    display(&q);
    // push(&q, 60);
    // display(&q);
    pop(&q);
    display(&q);
    pop(&q);
    display(&q);
    pop(&q);
    display(&q);
    pop(&q);
    display(&q);
    pop(&q);
    display(&q);
    pop(&q);
    display(&q);
}
