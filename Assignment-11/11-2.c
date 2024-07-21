//Implement Heap sort in C.
#include<stdio.h>
#include<stdlib.h>
#define max 100
int heapsize=0;
int queue[max];

void swap(int a,int b){
	int temp= queue[b];
	queue[b]=queue[a];
	queue[a]=temp;
}

void max_heapify(int i){
	int l=2*i;
	int r=2*i+1;
	int largest=i;
	
//	printf("%d\n",heapsize);
	if(l<=heapsize && queue[l]>=queue[i]){
		largest=l;
	}
	if(r<=heapsize && queue[r]>=queue[largest]){
		largest=r;
	}
	if(i!=largest){
		swap(i,largest);	
		max_heapify(largest);
	}
}

void display(int n){
	for(int i=1;i<=n;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}
void heap_sort(int n){
	heapsize=n;
	// int j=n/2;
	for(int j=n/2;j>=1;j--){
		max_heapify(j);
	}
	printf("After building the max heap, the heap\n");
	display(n);
	for(int i=n;i>=2;i--){
		swap(1,i);
		heapsize=heapsize-1;
		max_heapify(1);
	}
}



int main(){
	int n;
	printf("Enter the number of elements you want to insert\n");
	scanf("%d",&n);
	int num;
	for(int i=1;i<=n;i++){
		printf("Enter the %d element: ",i);
		scanf("%d",&num);
		queue[i]=num;
	}
	heap_sort(n);
	printf("After sorting, the heap is: \n");
	display(n);
}
