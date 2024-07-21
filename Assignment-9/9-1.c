//Implement Expression tree
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}

struct node* createnode(char data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* expressiontree(char postfix[]){
    struct node* stack[100];
    int top=-1;

    for (int i = 0; postfix[i]!='\0'; i++)
    {
        char symbol=postfix[i];
        if(isalnum(symbol)){
            struct node* node=createnode(symbol);
            stack[++top]=node;
        }
        else{
            struct node* rightoperator=stack[top--];
            struct node* leftoperator=stack[top--];

            struct node* node=createnode(symbol);
            node->left=leftoperator;
            node->right=rightoperator;
            stack[++top]=node;
        }
    }
    return stack[top];
}

int main(){
    char postfix[100];
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);

    struct node* root=expressiontree(postfix);

    printf("Inorder traversal of the expression tree is: \n");
    printf("%c\n",root->data);
    inorder(root);

    return 0;
}