//Write a menu driven C program to implement double ended queue.
#include<stdio.h>
#include<stdlib.h>
#define max 5
int f=-1,r=-1,q[max];
void enque_front(int n){
	if((f==0 && r==max-1)||(f==r+1)){
		printf("Queue is full");
	}
	else if(r==-1 && f==-1){
		f=0;
		r=0;
		q[f]=n;
	}
	else if(f==0){
		f=max-1;
		q[f]=n;
	}
	else{
		f--;
		q[f]=n;
	}
}
void enque_rear(int n){
	if((f==0 && r==max-1)||(f==r+1)){
		printf("Queue is full");
	}
	else if(r==-1 && f==-1){
		f=r=0;
		q[r]=n;
	}
	else if(r==max-1){
		r=0;
		q[r]=n;
	}
	else{
		r++;
		q[r]=n;
	}
}
void deque_front(){
	if(f==-1 && r==-1){
		printf("Queue is empty");
	}
	else if(f==r){
		printf("Dequed element is %d",q[f]);
		f=r=-1;
	}
	else if(f==max-1){
		printf("Dequed element is %d",q[f]);
		f=0;
	}
	else{
		printf("Dequed element is %d",q[f]);
		f++;
	}
}
void deque_rear(){
	if(f==-1 && r==-1){
		printf("Queue is empty");
	}
	else if(f==r){
		printf("Dequed element is %d",q[r]);
		f=r=-1;
	}
	else if(r==0){
		printf("Dequed element is %d",q[r]);
		r=max-1;
	}
	else{
		printf("Dequed element is %d",q[r]);
		r--;
	}
}
void display(){
	if(f==-1 && r==-1){
		printf("Queue is empty");
	}
	else{
		int i=f;
		while(i!=r){
			printf("%d ",q[i]);
			i=(i+1)%max;
		}
		if(i==r){
			printf("%d ",q[i]);
		}
		printf("\n");
	}
}
int main(){
	do{
		int a;
		printf("\nType 1 to enque_front\nType 2 to enque_rear\nType 3 to deque_front\nType 4 to deque_rear\nType 5 to display\nType 6 to exit\n");
		scanf("%d",&a);
		switch(a){
				int n;
			case 1:
				printf("Enter the element you want to enque\n");
				scanf("%d",&n);
				enque_front(n);
				break;
			case 2:
				// int n;
				printf("Enter the element you want to enque\n");
				scanf("%d",&n);
				enque_rear(n);
				break;
			case 3:
				deque_front();
				break;
			case 4:
				deque_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(1);
		}
	}while(1);
return 0;
}


