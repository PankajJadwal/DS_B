// Level order traversal
//left view
//right view
// Preorder inorder Postorder

#include <stdio.h>
#include <stdlib.h>
#define MS 5
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
    node *arr[MS];
} queue;
void init_q(queue *q)
{
    q->front = -1;
    q->rear = -1;
}
void push(queue *q, node *x)
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

node *pop(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf(" Underflow ho gaya hai brother\n");
        return;
    }
    if (q->front == q->rear)
    {
        node *c = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        return c;
    }
    node *c = q->arr[q->front];
    q->front = q->front + 1;
    return c;
}
int is_empty(queue *q)
{
    return (q->front == -1);
}
int getSize(queue *q)
{
    return q->rear + 1;
}
node *init(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
}
void level_order_traversal(node *root)
{
    queue q;
    init_q(&q);
    push(&q, root);
    while (!is_empty(&q))
    {
        node *c = pop(&q);
        printf("%d ", c->data);
        if (c->left != NULL)
        {
            push(&q, c->left);
        }
        if (c->right != NULL)
        {
            push(&q, c->right);
        }
    }
}
void left_view(node *root)
{
    queue q;
    init_q(&q);
    push(&q, root);
    while (!is_empty(&q))
    {
        int level_size = q.rear - q.front + 1;
        node *c;
        for (int i = 0; i < level_size; i++)
        {
            c = pop(&q);
            if (i == 0)
            {
                printf("%d ", c->data);
            }

            if (c->left != NULL)
            {
                push(&q, c->left);
            }
            if (c->right != NULL)
            {
                push(&q, c->right);
            }
        }
    }
}
void right_view(node *root)
{
    queue q;
    init_q(&q);
    push(&q, root);
    while (!is_empty(&q))
    {
        int level_size = q.rear - q.front + 1;
        node *c;
        for (int i = 0; i < level_size; i++)
        {
            c = pop(&q);
            if (i == level_size-1)
            {
                printf("%d ", c->data);
            }

            if (c->left != NULL)
            {
                push(&q, c->left);
            }
            if (c->right != NULL)
            {
                push(&q, c->right);
            }
        }
    }
}
int main()
{
    node *root = init(10);
    root->left = init(20);
    root->right = init(30);
    root->left->right = init(40);
    root->right->right = init(50);
    // preorder(root);
    // printf("\n");
    // inorder(root);
    // printf("\n");
    // postorder(root);
    // printf("\n");
    // level_order_traversal(root);
    left_view(root);
    // right_view(root);
}