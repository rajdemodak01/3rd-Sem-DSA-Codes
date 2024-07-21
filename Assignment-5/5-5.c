// Write a c program to implement Queue using Linked list.
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	int data;
	struct node* next;
};
struct node* head;
void insertion(int value){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=head;
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		head->prev=newnode;
		head=newnode;
	}
}
void deletion(){
	struct node* ptr=head;
	if(ptr==NULL){
		printf("Empty List. Nothing to delete");
		return;
	}
	else if(ptr->next==NULL){
		head=NULL;
		free(ptr);
		return;
	}
	else{
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr=ptr->prev;
		ptr->next=NULL;
		//free(ptr);
	}
}
void display(){
	struct node* ptr=head;
	if(ptr==NULL){
		printf("Empty list");
	}
	else{
		while(ptr!=NULL){
//			printf("%p ",ptr->prev);
			printf("%d ",ptr->data);
//			printf("%p ",ptr->next);
			ptr=ptr->next;
		}
	}
	printf("\n");
}
int main(){
   while(1){
        int a;
        printf("Type what do you want\n\tType 1 to insert\n\tType 2 to delete\n\tType 3 to display\n\tType 4 to exit\n");
        scanf("%d",&a);
        int value;
        switch(a){
                case 1:
                        printf("Enter the number you want to insert\t");
                        scanf("%d",&value);
                        insertion(value);
                        break;
                case 2:
                        deletion();
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        exit(1);
                        break;
                default:
                        exit(1);
        };
   }
   
}
