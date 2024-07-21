//Write a program to implement DFS in c.
#include<stdio.h>
#define max 100
int visited[max];
int graph[max][max];

void dfs(int v,int n){
	visited[v]=1;
	printf("%d ",v);
	
	for(int i=1;i<=n;i++){
		if(graph[v][i]!=0 && visited[i]==0){
			dfs(i,n);
		}	
	}
}

int main(){
	int m,n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&m);
	
	for(int i=1;i<=n;i++){
		visited[i]=0;		
		for(int j=1;j<=n;j++){
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
			dfs(i,n);
		}
	}
}
