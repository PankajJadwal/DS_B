// #include<stdio.h>
// void swap(int *x, int *y)
// {
//     int temp=*x;
//     *x=*y;
//     *y=temp;

// }
// int main()
// {
//     int a=2, b=3;
//     printf("a-->%d  b-->%d\n", a, b);
//     swap(&a, &b);
//     printf("a-->%d  b-->%d\n", a, b);

// }
#include <stdio.h>
#include <stdlib.h>
#define MS 5
typedef struct stack
{
    int top;
    int arr[MS];
    int size;
}stack;
void init(stack *s)
{
    s->size=0;
    s->top=-1;

}
void push(stack *s, int x)
{
    if(s->top==MS-1)
    {
        printf(" isse jyada nahi ho payega!!");
        return;
    }
    s->size++;
    s->arr[++s->top]=x;
}
void display(stack *s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d  ", s->arr[i]);
    }
}
int main()
{
    stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);
    display(&s);
}
