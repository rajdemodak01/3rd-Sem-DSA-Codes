#include <stdio.h>
void insertion(int arr[], int n, int pos, int val)
{
    pos++;
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    printf("The new array after insertion is\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void deletion(int arr[], int n, int pos, int val)
{
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("\n");
    printf("The new array after deletion is\n");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[100], n, val, new, pos;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    printf("Enter the elemets of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value after which element to delete and after which to insert\n");
    scanf("%d", &val);
    printf("Enter the new value to insert\n");
    scanf("%d", &new);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            pos = i;
            break;
        }
    }
    int arr1[n + 1];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
    }
    insertion(arr1, n, pos, new);
    deletion(arr, n, pos, val);
    return 0;
}