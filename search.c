#include <stdio.h>
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
int bsearch_f(int arr[], int n, int x)//First occurance
{
    int low = 0;// O(logn) TC  and O(1) Aux Space
    int high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x )
        {
            if((mid==0 || arr[mid]!=arr[mid-1]))
            {
                return mid;

            }
            
        }
       
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
         
    }
    return -1;
}
int bsearch(int arr[], int n, int x)
{
    int low = 0;// O(logn) TC  and O(1) Aux Space
    int high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if(mid==0 || arr[mid]!=arr[mid-1])
        {
            return mid;
        }
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int bsearch_r(int arr[], int n, int x, int low, int high)
{
    if (low > high) // O(logn) TC  and O(logn) Aux Space
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (x < arr[mid])
    {
        return bsearch_r(arr, n, x, low, mid - 1);
    }
    else
    {

        return bsearch_r(arr, n, x, mid + 1, high);
    }
}
int main()
{
    int arr[] = {1,2,2,3,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printf("%d ", search(arr,n,3));
    // printf("%d ", bsearch(arr, n, 2));
    printf("%d ", bsearch_f(arr, n, 3));
    // printf("%d ", bsearch_r(arr, n, 12, 0, n - 1));
}