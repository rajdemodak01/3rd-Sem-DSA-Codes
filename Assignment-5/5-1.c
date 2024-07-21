//Implement Singly Linked List and related operations  like insertion, deletion, display, reverse and sort in C. 
#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;                                              
};
struct node *list;
void insertion_first(int item){
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=item;
        newNode->next=NULL;
        if(list==NULL){
                list=newNode;
        }
        else{
                newNode->next=list;
                list=newNode;
        }
}
void insertion_last(int item){
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=item;
        newNode->next=NULL;
        struct node *temp=list;
        while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next=newNode;
}
void deletion(int value){
        if(list->data==value){
                list=list->next;
        }
        else{
        struct node *temp=list,*previous=list;
        if(list==NULL){printf("List is empty");}
        while(temp->data!=value){
                previous=temp;
                temp=temp->next;
        }
        previous->next=temp->next;}
}
void reverse(){
        struct node *curr=list,*next=list,*prev=NULL;
        while(next!=NULL){
                curr=next;
                next=curr->next;
                curr->next=prev;
                prev=curr;
        }
        list=curr;
}
void sort() {
    if (list == NULL || list->next == NULL)
        return;

    struct node* current;
    struct node* temp = NULL;
    int swapped;

    do {
        swapped = 0;
        current = list;

        while (current->next != temp) {
            if (current->data > current->next->data) {
                int tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = 1;
            }
            current = current->next;
        }
        temp = current;
    } while (swapped);
}
void display(){
        struct node *temp=list;
        while(temp->next!=NULL){
                printf("%d\t",temp->data);
                temp=temp->next;
        }
        printf("%d\n",temp->data);
}
int main(){
   while(1){
        int a;
        printf("Type what do you want\n\tType 1 to insert from first\n\tType 2 to insert from last\n\tType 3 to delete\n\tType 4 to reverse\n\tType 5 to sort\n\tType 6 to display\n\tType 7 to exit:\n");
        scanf("%d",&a);
        int value;
        switch(a){
                case 1:
                        printf("Enter the number you want to insert\t");
                        scanf("%d",&value);
                        insertion_first(value);
                        break;
                case 2:
                        printf("Enter the number you want to insert\t");
                        scanf("%d",&value);
                        insertion_last(value);
                        break;
                case 3:
                        printf("Enter the number you want to delete\t");
                        scanf("%d",&value);
                        deletion(value);
                        break;
                case 4:
                        reverse();
                        break;
                case 5:
                        sort();
                        break;
                case 6:
                        display();
                        break;
                case 7:
                        exit(1);
                        break;
                default:
                        exit(1);
        };
   }
   
}
