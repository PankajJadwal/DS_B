#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}node;
node* init(int x)
{
    node* temp=(node*)malloc(sizeof(node));

    temp->data=x;
    temp->next=NULL;
    return temp;
}
void display(node* head)
{
    node* c=head;
    while(c)
    {
        printf("%d ", c->data);
        c=c->next;
    }
    printf("\n");
}
node* ins_b(node* head, int x)
{
    node* temp=init(x);
    if (head==NULL)
    {
        return temp;

    }
    temp->next=head;
    return temp;
}
node* ins_l(node* head, int x)
{
    node* temp=init(x);
    if(head==NULL)
    {
        return temp;

    }
    node* c=head;
    while(c->next)
    {
        c=c->next;
    }
    c->next=temp;
    return head;
}
node* ins_p(node* head, int x , int pos)
{
    node* temp=init(x);
    if(head==NULL)
    {
        return temp;
    }
    int count=0;
    node* c=head;
    while(c)
    {
        count=count+1;
        c=c->next;

    }
    if(pos>count)
    {
        return head;
    }
    // if (pos==count)
    // {
    //     return ins_l(head, x);
    // }
    c=head;
    for(int i=1;i<=pos-2;i++)
    {
        c=c->next;
    }
    temp->next=c->next;
    c->next=temp;
    return head;

}
node* del_b(node* head)
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
node* del_l(node* head)
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
node* del_p(node* head, int pos)
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
     int count=0;
    node* c=head;
    while(c)
    {
        count=count+1;
        c=c->next;

    }
     if(pos>count)
    {
        return head;
    }
    c=head;
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
    node* head=init(10);
    node* second=init(20);
    node* third=init(30);
    node* forth=init(40);
    node* fifth=init(50);
    head->next=second;
    second->next=third;
    third->next=forth;
    forth->next=fifth;
    display(head);
    head=ins_b(head, 1);
    display(head);
    head=ins_l(head, 60);
    display(head);
    head=ins_p(head, 99, 3);
    display(head);
    head=del_b(head);
    display(head);
    head=del_l(head);
    display(head);
    head=del_p(head,3);
    display(head);
}