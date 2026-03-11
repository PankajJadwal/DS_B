#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *init(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
node *push(node *head, int x)
{
    node *temp = init(x);
    if (head == NULL)
    {
        return temp;
    }
    temp->next=head;
    return temp;
    
}
void display(node *head)
{
    if(head==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    node *c = head;
    while (c)
    {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
}
node *pop(node *head)
{
    if(head->next==NULL)
    {
        return NULL;
    }
    if (head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
   
    node *temp = head;
    head=head->next;
    free(temp);
    return head;
}
int main()
{
    node *head = NULL;
    // node* head=init(10);
    head = push(head, 10);
    display(head);
    head = push(head, 20);
    display(head);
    head = push(head, 30);
    display(head);
    head = push(head, 40);
    display(head);
    head = pop(head);
    display(head);
    head = pop(head);
    display(head);
    head = pop(head);
    display(head);
    head = pop(head);
    display(head);
}