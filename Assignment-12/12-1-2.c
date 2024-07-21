// binary_search
#include<stdio.h>

int binary_search(int arr[],int key,int n){
	int s=0,e=n-1;
	while(s<=e){
		int mid=e-(e-s)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(key>arr[mid]){
			s=mid+1;
		}
		else if(key<arr[mid]){
			e=mid-1;
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
	
	int ans=binary_search(arr,key,n);
	if(ans!=-1){
		printf("Element is found in position %d.\n",ans);
	}else{
		printf("Element is not found");
	}
	return 0;
}
