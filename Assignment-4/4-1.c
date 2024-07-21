//Write a menu driven c program to implement linear queue using array.
#include<stdio.h>
#include<stdlib.h>
#define max 100
int f=-1,r=-1,q[max];
void enque(int n){
	if(r==max-1){
		printf("Queue is full");
	}
	else if(r==-1 && f==-1){
		f=r=0;
		q[r]=n;
	}
	else{
		r++;
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
		f++;
	}
}
void peek(){
	printf("The peeked element is %d",q[f]);
}
void display(){
	if(f==-1 && r==-1){
		printf("Queue is empty");
	}
	else{
	for(int i=f;i<=r;i++){
		printf("%d ",q[i]);
	}
	}
}
int main(){
	do{
		int a;
		printf("\nType 1 to enque\nType 2 to deque\nType 3 to display\nType 4 to peek\nType 5 to exit\n");
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
				peek();
				break;
			case 5:
				exit(1);
		}
	}while(1);
return 0;
}

