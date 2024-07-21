//Write a menu driven c program to implement Circular queue.
#include<stdio.h>
#include<stdlib.h>
#define max 3
int f=-1,r=-1,q[max];
void enque(int n){
	if((r+1)%max==f){
		printf("Queue is full");
	}
	else if(r==-1 && f==-1){
		f=r=0;
		q[r]=n;
	}
	else{
		r=(r+1)%max;
		q[r]=n;
	}
}
void deque(){
	if(f==-1 && r==-1){
		printf("Queue is empty");
	}
	else if(f>r){
		f=r=-1;
	}
	else{
		printf("Dequed element is %d",q[f]);
		f=(f+1)%max;
	}
}
void display(){
	if(f==-1 && r==-1){
		printf("Queue is empty");
	}
	else{
	for(int i=0 ;i<max;i++){
		printf("%d ",q[i]);
	}
	}
}
int main(){
	do{
		int a;
		printf("\nType 1 to enque\nType 2 to deque\nType 3 to display\nType 4 to exit\n");
		scanf("%d",&a);
		switch(a){
			case 1:
				int n;
				printf("Enter the element you want to enque\n");
				scanf("%d",&n);
				enque(n);
				break;
			case 2:
				deque();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
		}
	}while(1);
return 0;
}

