// insertion sort
#include<stdio.h>
#include<stdlib.h>	

void sort(int *arr, int size){
	for(int i = 1; i < size; i++){
		//taking the element and putting the element in the sorted part with its actual position
		int key = arr[i];
		int j = i - 1;
		while(j >=0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void printArray(int *arr, int size){	
	for(int i = 0; i< size; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int main(){
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int *arr = (int *)malloc(sizeof(int) * size);
	
	printf("Enter the elements of the array: ");
	for(int i = 0; i< size; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("The unsorted array is: \n");
	
	printArray(arr, size);
		
	sort(arr, size);
	
	printf("The sorted array is: \n");
	
	printArray(arr, size);
	
	return 0;
}
