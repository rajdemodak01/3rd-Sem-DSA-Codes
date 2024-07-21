#include<stdio.h>
#include<stdlib.h>

void insertion(int arr[],int key,int size){
	int i=0;
	int hkey=key%size;
	while(i<size){
		int index=(hkey+i)%size;
		if(arr[index]==-1){
			arr[index]=key;
			return;
		}
		i++;
	}
}
int searching(int arr[],int key,int size){
	int i=0;
	int hkey=key%size;
	while(i<size){
		int index=(hkey+i)%size;
		if(arr[index]==key){
			return index;
		}
		i++;
	}
	return -1;
}

void print(int arr[],int size){
	for(int i=0;i<size;i++){
		if(arr[i]!=-1){
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}
int main(){
	int choice;
	int size=5;
	int arr[size];
	for(int i=0;i<size;i++){
		arr[i]=-1;
	}
	while(1){
		printf("Enter what do you want to do:\n\t1.Enter 1 for inserting\n\t2.Enter 2 for searching\n\t3.Enter 3 for printing.\n\t4.Enter 4 to exit.\n");
		scanf("%d",&choice);
		switch(choice){
			int n;
			case 1:
				printf("Enter the number you want to insert\n");
				scanf("%d",&n);
				insertion(arr,n,size);
				break;
			case 2:
				printf("Enter the element you want to search:\n");
				scanf("%d",&n);
				int ans=searching(arr,n,size);
				if(ans!=-1){			
					printf("Element is found in index %d\n",ans);
				}else{
					printf("Element is not found\n");
				}
				break;
			case 3:
				print(arr,size);
				break;
			case 4:
				exit(1);
			default:
				break;
		}
	}
	return 0;
}
