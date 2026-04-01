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
void display(node *head)
{
    node *c = head;
    while (c != NULL)
    {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
}
int getsize(node *head)
{
    int size = 0;
    node *c = head;
    while (c)
    {
        size = size + 1;
        c = c->next;
    }
    return size;
}
node *insert_b(node *head, int x)
{
    node *temp = init(x);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    return temp;
}
node *insert_l(node *head, int x)
{
    node *temp = init(x);
    if (head == NULL)
    {
        return temp;
    }
    node *c = head;

    while (c->next != NULL)
    {
        c = c->next;
    }
    c->next = temp;
    return head;
}
node *insert_p(node *head, int x, int pos)
{
    int size = getsize(head);
    node *temp = init(x);
    if(size==0)
    {
        return temp;

    }
    
    node* c=head;
    {
        if (pos < 0)
            return head;
        if (pos > size)
            return head;

        for(int i=1;i<=pos-2;i++)
        {
            c=c->next;

        }
        temp->next=c->next;
        c->next=temp;
        return head;
    }
}
node* delete_b(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
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
    int size=getsize(head);
    if(pos<0)   return head;
    if(pos>size)  return head;
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
    node *head = init(10);
    node *fi = init(20);
    node *se = init(30);
    node *th = init(40);
    node *fo = init(50);
    head->next = fi;
    fi->next = se;
    se->next = th;
    th->next = fo;
    // display(head);
    // head = insert_b(head, 60);
    // display(head);
    // head = insert_l(head, 70);
    display(head);
    // printf("%d  ", getsize(head));
    head = insert_p(head, 100, -5);
    display(head);
    head=delete_b(head);
    display(head);
    head=delete_l(head);
    display(head);
    head=delete_p(head, 2);
    display(head);
}