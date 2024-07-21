#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int x;
	struct node *n;
} node;


node *head = NULL;

void push(){
	node *n = (node*)malloc(sizeof(node));
	if(head == NULL){
		head = n;
		
	}else{
		n->n=head;
		head=n;
	}
	printf("Enter val: ");
	scanf("%d",&n->x);
	
}


void pop(){
	if(head == NULL){
		printf("Empty!\n");
	}else{
		printf("Popped: %d\n",head->x);
		head=head->n;
	}	
}

void disp(){
	node* nn = head;
	if(head==NULL) {
		printf("Empty!\n");
		return;
	}
	while(nn!=NULL){
		printf("%d, ",nn->x);
		nn=nn->n;
	}
	printf("\n");
}


int main(){
	int ch = 4;
	while(1){
		printf("1. Push 2. Pop 3. Display 4. Exit\n>_");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				disp();
				break;
			case 4:
				printf("Bye.\n");
				return 0;
			default:
				printf("Invaid Input.\n");
				return 1;
		}
	}
	return 0;
}
