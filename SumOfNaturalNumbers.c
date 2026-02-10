#include<stdio.h>
int fun1(int n)   
{
    return n*(n+1)/2;
}
int fun2(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    return sum;
}
int fun3(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            sum++;
        }
    }
    return sum;
}
int fun4(int n)
{
    if(n==1) return 1;
    return n+fun4(n-1);
}

int main()
{
    printf("%d  ", fun1(5));
    printf("%d  ", fun2(5));
    printf("%d  ", fun3(5));
    printf("%d  ", fun4(5));
}