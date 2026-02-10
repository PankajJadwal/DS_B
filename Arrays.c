#include <stdio.h>
void display(int arr[], int n)
{
    printf("Array elements--->\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int insert_beg(int arr[], int n, int x)
{
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = x;
    return n + 1;
}
int insert_pos(int arr[], int n, int pos, int x)
{
    if (pos >= n)
        return n;
    if (pos < 0)
        return n;
    for (int j = n - 1; j >= pos; j--)
    {
        arr[j + 1] = arr[j];
    }
    arr[pos] = x;
    return n + 1;
}
int delete(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            break;
        }
    }
    if (i == n)
        return n;
    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    return n - 1;
}
int getmaxx(int arr[], int n)
{
    int maxx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    return maxx;
}
int isSorted(int arr[], int n) // O(n2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            return 0;
        }
    }
    return 1;
}
int isSorted_optimized(int arr[], int n) // O(n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

void reverse(int arr[], int n)  // O(n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int temp;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    
}
int getsmax(int arr[], int n)
{
    int max=arr[0];
    int smax=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            smax=max;
            max=arr[i];
        }
        if(arr[i]<max && arr[i]>smax)
        {
            smax=arr[i];
        }
    }
    return smax;

}
int main()
{
    int arr[10] = {5,5,5,5,5};
    // int n=sizeof(arr)/sizeof(arr[0]);
       int n = 5;
    // display(arr, n);
    // printf("%d\n", search(arr, n, 15));
    // n = insert_beg(arr, n, 100);
    // printf("%d", n);
    // display(arr, n);
    // n = insert_pos(arr, n, -2, 99);
    // display(arr, n);
    // n = delete(arr, n, 10);
    // display(arr, n);
    // printf("Max elemnt is-->%d", getmaxx(arr, n));
    // printf("%d  ", isSorted(arr, n));
    // printf("%d", isSorted_optimized(arr, n));
    // reverse(arr, n);
    // display(arr, n);
    // printf("%d ", getsmax(arr,n));
   
}