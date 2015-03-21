#include<stdio.h>
#include<stdlib.h>
#define V 7
typedef struct node* link;
struct node{
	int v;
	link next;
};

link NEW(int v, link next){
	link x = malloc(sizeof *x);
	x->v = v;
	x->next = next;
	return x;
}

int main(){
	int i, j;
	link adj[V], temp;
	for(i = 0; i < V; i++)
		adj[i] = NULL;
	while(scanf("%d %d", &i, &j) == 2){
		if(i == j)
			break;
		adj[j] = NEW(i, adj[j]);
		adj[i] = NEW(j, adj[i]);
	}
	for(i = 0; i < V; i++){
		temp = adj[i];
		while(temp != NULL){
			printf("%d\t", temp->v);
			temp = temp->next;
		}
	}
	printf("\n");
	return 0;
}
