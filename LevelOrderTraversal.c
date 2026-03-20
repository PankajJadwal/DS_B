#include <stdio.h>
#include <stdlib.h>
#define MS 10
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
typedef struct queue
{
    int front;
    int rear;
    node* arr[MS];
} queue;
void init_q(queue *q)
{
    q->front=-1;
    q->rear=-1;
}
void push(queue *q, node* x)
{
     if (q->rear == MS - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = x;
   

}
int empty(queue *q)
{
    return (q->front>q->rear);
}
node* pop(queue *q)
{
    if (empty(q))
        return NULL;

    if(q->front==q->rear)
    {
         node *x = q->arr[q->front];
    q->front++;
    return x;
        
    }

    node *x = q->arr[q->front];
    q->front++;
    return x;

}

node *init(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void display_tree(node *root)
{
    queue q;
    init_q(&q);
    push(&q, root);
    while(!empty(&q))
    {
        node* temp=pop(&q);
        printf("%d ", temp->data);
        if(temp->left!=NULL)
        {
            push(&q, temp->left);
        }
        if(temp->right!=NULL)
        {
            push(&q, temp->right);
        }

    }

}
int main()
{
    node *root = init(10);
    node *l = init(20);
    node *r = init(30);
    node *ll = init(40);
    node *rr = init(50);
    root->left = l;
    root->right = r;
    root->left->left = ll;
    root->right->right = rr;
    display_tree(root);
}