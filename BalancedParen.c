#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MS 100

typedef struct
{
    char arr[MS];
    int top;
} stack;

void init(stack *s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

void push(stack *s, char x)
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
    if (isEmpty(s))
    {
        return '\0';  // return null character if empty
    }
    return s->arr[(s->top)--];
}

int isMatchingPair(char open, char close)
{
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int isBalanced(char *str)
{
    stack s;
    init(&s);

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        // If opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty(&s))
                return 0;

            char top = pop(&s);

            if (!isMatchingPair(top, ch))
                return 0;
        }
    }
return isEmpty(&s);
}

int main()
{
    char str[100];

    printf("Enter expression: ");
    scanf("%s", str);

    if (isBalanced(str))
        printf("Balanced Parenthesis\n");
    else
        printf("Not Balanced\n");

    return 0;
}
