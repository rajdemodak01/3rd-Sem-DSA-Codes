//Write a program to implement BFS in c.
#include<stdio.h>
#define max 100
int visited[max];
int graph[max][max];
int queue[max];
int front=-1;
int rear=-1;

void enqueue(int value){
	if(rear==max-1){
		printf("Queue is full\n");
	}
	else{
		if(front=-1){
			front=0;
		}
		rear++;
		queue[rear]=value;
	}
}

int dequeue(){
	int value=-1;
	if(front==-1 || front>rear){
		printf("Queue is empty\n");
	}
	else{
		if(front==rear){
			//printf("ok4");
			value=queue[front];
			front=rear=-1;
		}
		else{
			value=queue[front];
			front++;
		}
	}
	return value;
}

void bfs(int v,int n){
	visited[v]=1;
	enqueue(v);
	
	while(front!=-1){
		int p=dequeue();
		printf("%d ",p);
		for(int i=1;i<=n;i++){
			if(graph[v][i]!=0){
				//printf("ok2\n");
				if(visited[i]==0){
					visited[i]=1;
					enqueue(i);
				}
				//break;
			}
		}
	}
}

void bfs2(int v,int n){
	visited[v]=1;
	enqueue(v);
	
	while(front!=-1){
		int p=dequeue();
		printf("%d ",p);
		for(int i=0;i<n;i++){
			if(graph[v][i]!=0){
				//printf("ok2\n");
				if(visited[i]==0){
					visited[i]=1;
					enqueue(i);
				}
				break;
			}
		}
	}
}
void bfs3(int v, int n){
	visited[v]=1;
	enqueue(v);
	
	while(front!=-1){
		//printf("ok3\n");
		int p=dequeue();
		printf("%d ",p);
		
		for(int i=1;i<=n;i++){
			if(graph[v][i]!=0 && visited[i]==0){
				//printf("ok2\n");
				visited[i]=1;
				enqueue(i);
			}
		}
	}
}

int main(){
	int m,n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&m);
	
	for(int i=0;i<=n;i++){
		visited[i]=0;		
		for(int j=0;j<=n;j++){
			graph[i][j]=0;
		}
	}
	
	for(int i=0;i<m;i++){
		int u,v;
		printf("Enter the edges\n");
		scanf("%d %d",&u,&v);
		graph[u][v]=graph[v][u]=1;
	}
	
	//for(int i=0;i<n;i++){		
	//	for(int j=0;j<n;j++){
	//		printf("%d ",graph[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("\n");
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			//printf("ok1");
			bfs(i,n);
		}
	}
}
