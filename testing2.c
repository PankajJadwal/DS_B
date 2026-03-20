#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
node* init(int x)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
}
int getSize(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return getSize(root->left)+getSize(root->right)+1;

}
int maxx(int a, int b)
{
    return (a>b?a:b);
}
int getheight(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return maxx(getSize(root->left),getSize(root->right))+1;

}
int main()
{
    node* root=init(10);
    root->left=init(20);
    root->right=init(30);
    root->left->left=init(40);
    root->right->right=init(50);
    root->right->right->right=init(60);
    printf("%d  \n", getSize(root));
    printf("%d  \n", getheight(root));

}
