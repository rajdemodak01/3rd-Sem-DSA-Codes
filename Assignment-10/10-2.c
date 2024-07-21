// mergeSort
#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *arr, int s, int e){
	if (s < e) {
        int m = (s + e) / 2;
	
		//splitting the arr
		mergeSort(arr, s, m);
		mergeSort(arr, m + 1, e);	
		
		int size1 = m - s + 1;
		int size2 = e - m;
		
		int arr1[size1];
		int arr2[size2];
		
		//copying elements in arr1 from arr
		for(int i = 0; i < size1; i++){
			arr1[i] = arr[s + i];
		}
		
		//copying elements in arr2 from arr
		for(int i = 0; i < size2; i++){
			arr2[i] = arr[m + 1 + i];
		}
		

		//merging the array
		int i = 0, j = 0, k = s;
		while(i < size1 && j < size2){
			if(arr1[i] < arr2[j]){
				arr[k++] = arr1[i++];
			}else{
				arr[k++] = arr2[j++];
			}
		}
		
		while(i < size1){
			arr[k++] = arr1[i++];
		}
		
		while(j < size2){
			arr[k++] = arr2[j++];
		}
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
	
	printf("The sorted array is: \n");
	mergeSort(arr, 0, size - 1);
	
	printArray(arr, size);
		
	return 0;
}
