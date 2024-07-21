//Create Priority Queue and implement enqueue and dequeue operations in C.
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

void insertion(int key){
	heapsize=heapsize+1;
	
	queue[heapsize]=key;
	
	int i=heapsize;
	
	while(i>1){
		if(queue[i/2]<queue[i]){
			swap(i,i/2);
		}
		i--;	
	}
}

int deletion(){
	if(heapsize<1){
		printf("Error");
		return -1;
	}
	else{
		int temp=queue[1];
		queue[1]=queue[heapsize];
		heapsize=heapsize-1;
//		printf("%d\n",heapsize);
		max_heapify(1);
		return temp;
	}
}
void display(){
	for(int i=1;i<=heapsize;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}

int main(){
	int choice=0;
	while(1){
		printf("Enter what do you want\n\t1.Enter 1 for insertion\n\t2.Enter 2 for deletion\n\t3.Enter 3 for display\n\t4.Enter 4 for exit\n");
		scanf("%d",&choice);
		int num;
		switch(choice){
			case 1:
				printf("Enter the number you want to insert\n");
				scanf("%d",&num);
				insertion(num);
				break;
			case 2:
				num=deletion();
				printf("The deleted element is %d\n",num);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
		}
	}
}

