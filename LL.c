#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;

} node;
node *create(int x)
{
    node *temp = ((node *)malloc(sizeof(node)));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void display(node * head)
{
    node* curr=head;
    while(curr)
    {
        printf("%d ", curr->data);
        curr=curr->next;
    }
    printf("\n");
}
node* insert_b(node* head,int x)
{
    node* temp=create(x);
    temp->next=head;
    return temp;
}
node* insert_l(node* head,int x)
{
    node* temp=create(x);
    node* c=head;
    while(c->next)
    {
        c=c->next;
    }
    c->next=temp;
    return head;
}
node* insert_p(node* head,int x, int pos)
{
    node* temp=create(x);
    node* c=head;
    for(int i=1;i<=pos-2;i++)
    {
        c=c->next;

    }
    temp->next=c->next;
    c->next=temp;
   
    return head;
}
node* delete_b(node* head)
{
    node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
node* delete_l(node* head)
{
    node* c=head;
    while(c->next->next)
    {
        c=c->next;
    }
    node* temp=c->next;
    c->next=NULL;
    free(temp);
    return head;
    
}
node* delete_p(node* head, int pos)
{
    node* c=head;
    for(int i=1;i<=pos-2;i++)
    {
        c=c->next;
    }
    node* temp=c->next;
    c->next=c->next->next;
    free(temp);
    return head;
    
    
}

int main()
{
    node *head = create(10);
    node *first = create(20);
    node *second = create(30);
    node *third = create(40);
    head->next=first;
    first->next=second;
    second->next=third;
    display(head);
    head=insert_b(head,100);
    display(head);
    head=insert_l(head,1000);
    display(head);
    head=insert_p(head,999,3);
    display(head);
    head=delete_b(head);
    display(head);
    head=delete_l(head);
    display(head);
    head=delete_p(head,4);
    display(head);
}