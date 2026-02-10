#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++) // TC O(n2)  Aux: O(c)
    {
        int flag = 1;
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}
void bubble_sort_rec(int arr[], int n)
{
    if (n == 1) // TC O(n2)    Aux space: O(n)
    {
        return;
    }
    for (int j = 0; j <= n - 2; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
    bubble_sort_rec(arr, n - 1);
}
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void selection_sort_rec(int arr[], int n, int i)
{
    if (i == n)
    {
        return;
    }

    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;

    selection_sort_rec(arr, n, i + 1);
}
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        while (i > 0 && arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
}
void insertion_sort_rec(int arr[], int n, int i)
{   
    if(i==n)  return;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
        insertion_sort_rec(arr,n,i+1);
    
}
int partition(int arr[], int p, int r)
{
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(arr[j]<x)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[p];
            arr[p]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return i+1;
}
void qs(int arr[], int p, int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);
        qs(arr,p,q-1);
        qs(arr,q+1,r);

    }
}
void merge(int arr[], int low, int mid, int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[low+i];

    }
    for(int j=0;j<n2;j++)
    {
        arr2[j]=arr[j+mid+1];

    }
    int i=0;
    int j=0;
    int k=low;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            i++;
            k++;

        }
        else
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }

    }
    while(i<n1)
    {
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        k++;
        j++;
    }

}
void merge_sort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(arr, low,mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

}
int main()
{
    int arr[] = {50, 40, 30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    // bubble_sort(arr, n);
    // bubble_sort_rec(arr, n);
    // selection_sort(arr,n);
    // selection_sort_rec(arr, n, 0);
    // insertion_sort(arr, n);
    // insertion_sort_rec(arr, n,1);
    qs(arr,0,n-1);
    merge_sort(arr,0,n-1);
    display(arr, n);
}




      