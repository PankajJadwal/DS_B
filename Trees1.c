#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
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
int getmax(node* root)
{
    if(root==NULL)
    {
        return -1e9;
    }
    int l=getmax(root->left);
    int r=getmax(root->right);
    int ans=(root->data> l && root->data>r)?root->data:(l>r?l:r);
    return ans;
}
int getcount(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return getcount(root->left)+getcount(root->right)+1;
}
int maxx(int a, int b)
{
    return a>b?a:b;
}
int getheight(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return maxx(getcount(root->left),getcount(root->right))+1;
}
int getcountnodes(node* root)
{
    if(root==NULL)  return 0;

    return getcountnodes(root->left)+getcountnodes(root->right)+root->data;
}
int main()
{   
    // node *root = init(10);
    // root->left = init(20);
    // root->right = init(30);
    // root->left->left = init(40);
    // root->right->right = init(50);

    node* root=init(10);
    node* twenty=init(20);
    node* thirty=init(30);
    node* forty=init(40);
    node* fifty=init(50);
    root->left=twenty;
    root->right=thirty;
    root->left->left=forty;
    root->right->right=fifty;

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("Max among nodes--> %d\n  ",getmax(root));
    printf("Number of  nodes--> %d\n  ",getcount(root));
    printf("Height of the tree --> %d\n  ",getheight(root));
    printf("count of  all the nodes--> %d\n  ",getcountnodes(root));
    




}