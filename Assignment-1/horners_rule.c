#include <stdio.h>
// int Horner(int arr[], int n, int x, int index)
// {
//     if (index == n)
//         return arr[index];
//     else
//         return x * Horner(arr, n, x, index + 1) + arr[index];
// }
int Horner(int arr[], int n, int x, int index)
{
    if (index == 0)
    {
        return arr[index];
    }
    else
    {
        return arr[index] + x * Horner(arr, n, x, index - 1);
    }
}
int main()
{
    int arr[100], n, val;
    printf("Enter the size of the polynomial\n");
    scanf("%d", &n);
    printf("Enter the elemets of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value\n");
    scanf("%d", &val);
    printf("%d", Horner(arr, n, val, n - 1));
}