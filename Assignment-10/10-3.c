//Quick Sort
#include <stdio.h>

// Function to partition the array and return the index of the pivot element
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
    pivot=first;
    i=first;
    j=last;
    while(i<j){
        while(number[i]<=number[pivot]&&i<last)
            i++;
        while(number[j]>number[pivot])
            j--;
        if(i<j){
            // swapping number[i] and number[j]
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
        }
    }

    // swapping nummber[pivot] annd number[j]
    temp=number[pivot];
    number[pivot]=number[j];
    number[j]=temp;
    
    quicksort(number,first,j-1);
    quicksort(number,j+1,last);
   }
}

// Function to print an array
void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Before sorting, the array is: ");
    printarray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("After sorting, the array is: ");
    printarray(arr, n);

    return 0;
}
