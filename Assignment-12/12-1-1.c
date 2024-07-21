//linear_search
#include<stdio.h>

int linear_search(int arr[],int key,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}

int main(){	
	int n,key;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		printf("Enter the number\n");
		scanf("%d",&arr[i]);
	}
	printf("Enter the key you want to search\n");
	scanf("%d",&key);
	
	int ans=linear_search(arr,key,n);
	if(ans!=-1){
		printf("Element is found in position %d.\n",ans);
	}else{
		printf("Element is not found");
	}
	return 0;
}
