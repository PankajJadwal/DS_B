#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MS 30
typedef struct stack
{
    int arr[MS];
    int top;
} stack;
void push(stack *s, int x)
{
    if (s->top == MS - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

char pop(stack *s)
{
    // if (isEmpty(s))
    // {
    //     return '\0'; // return null character if empty
    // }
    return s->arr[(s->top)--];
}
// void display(stack *s)
// {
//     for (int i = 0; i <= s->top; i++)
//     {
//         printf("%d  ", s->arr[i]);
//     }
//     printf("\n");
// }

int fun(char arr[])
{
    stack s;
    s.top = -1;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4'||
            arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8'||
            arr[i] == '9'|| arr[i] == '0')
        {
            push(&s, (arr[i] - '0'));
            // display(&s);
        }
        else
        {
            int x = pop(&s);
            int y = pop(&s);
            if (arr[i] == '+')
            {
                push(&s, y + x);
            }
            else if (arr[i] == '-')
            {
                push(&s, y - x);
            }
            else if (arr[i] == '*')
            {
                push(&s, x * y);
            }
            else if (arr[i] == '/')
            {
                push(&s, y / x);
            }
        }
    }
    return pop(&s);
}
int main()
{
    char postfix[] = "23*62/+";
    printf("%d ", fun(postfix));
}
