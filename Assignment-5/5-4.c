//d)  Implement Doubly Linked List and perform insertion, deletion, display and reverse in C.
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
void deletion(int value){
	struct node* ptr=head;
	int count=0;
	if(ptr==NULL){
		printf("Empty List. Nothing to delete");
	}
	else if(ptr->next==NULL){
		head=NULL;
		free(ptr);
	}
	else{
		while(ptr->data!=value){
			ptr=ptr->next;
			count++;
		}
		if(count==0){
			ptr=ptr->next;
			ptr->prev=NULL;
			head=ptr;
		}
		else if(ptr->next==NULL){
			ptr=ptr->prev;
			ptr->next=NULL;
			//free(ptr);
		}
		else{
			// struct node* tempnext=ptr->next;
			// struct node* tempprev=ptr->prev;
			// ptr=ptr->next;
			// ptr->prev=tempprev;
			// ptr=ptr->prev;
			// ptr->next=tempnext;
			//free(ptr);

			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
		}
	}
}
void reverse(){
	struct node* next=head,*curr=head,*prev=NULL;
	if(head==NULL){
		return;
	}
	while(next!=NULL){
		curr=next;	
		next=next->next;
		curr->next=prev;
		curr->prev=next;
		prev=curr;
	}
	curr->prev=NULL;
	head=curr;
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
        printf("Type what do you want\n\tType 1 to insert\n\tType 2 to delete\n\tType 3 to reverse\n\tType 4 to display\n\tType 5 to exit\n");
        scanf("%d",&a);
        int value;
        switch(a){
                case 1:
                        printf("Enter the number you want to insert\t");
                        scanf("%d",&value);
                        insertion(value);
                        break;
                case 2:
                        printf("Enter the number you want to delete\t");
                        scanf("%d",&value);
                        deletion(value);
                        break;
                case 3:
                        reverse();
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(1);
                        break;
                default:
                        exit(1);
        };
   }
   
}
