//Create binary search tree and implement Preorder, Inorder, and Postorder travesal non recurisively in C
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;	
};
struct Node* createnode(int data){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

struct Node* insertnode(struct Node* root,int data){
	if(root==NULL){
		return createnode(data);
	}
	if(data>(root->data)){
		root->right=insertnode(root->right,data);
	}
	if(data<(root->data)){
		root->left=insertnode(root->left,data);
	}
	return root;
}
void postorder2(struct Node* root){
	if(root==NULL){
		return;
	}
	postorder2(root->left);
	postorder2(root->right);
	printf("%d ",root->data);
}
void preorder(struct Node* root){
	if(root==NULL){
		return;
	}
	struct Node* stack[100];
	int top=-1;
	stack[++top]=root;
	while(top>=0){
		struct Node* node=stack[top--];
		printf("%d ",node->data);
		if(node->right){
			stack[++top]=node->right;
		}
		if(node->left){
			stack[++top]=node->left;
		}
		
	}
}
void inorder(struct Node* root){
	if(root==NULL){
		return;
	}
	struct Node* stack[100];
	int top=-1;
	struct Node* node=root;
	while(top>=0||node!=NULL){
		while(node!=NULL){
			stack[++top]=node;
			node=node->left;
		}
		node=stack[top--];
		printf("%d ",node->data);
		node=node->right;
	}
}

void postorder(struct Node* root){
	if(root==NULL){
		return;
	}
	struct Node* stack1[100];
	struct Node* stack2[100];
	int top1=-1;
	int top2=-1;
	stack1[++top1]=root;
	while(top1>=0){
		struct Node* node=stack1[top1--];
		stack2[++top2]=node;
		
		if(node->left){
			stack1[++top1]=node->left;
		}
		if(node->right){
			stack1[++top1]=node->right;
		}
	}
	while(top2>=0){
		struct Node* node=stack2[top2--];
		printf("%d ",node->data);
	}
}
int main(){
	struct Node* root=NULL;
	int data;
	do{
		printf("Enter the number you want to insert or type -1 to break\n");
		scanf("%d",&data);
		if(data==-1){
			break;
		}
		root=insertnode(root,data);
	}while(data!=-1);
	printf("Preorder:\n");
	preorder(root);
	printf("\n");
	printf("Inorder:\n");
	inorder(root);
	printf("\n");
	printf("Postorder:\n");
	postorder(root);
}
