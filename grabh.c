/*
*Adjacency-matrix graph repersentation
*/

#include<stdio.h>
#define V 8
int main(){
	int i, j;
	int a[V][V];
	//Init graph
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
			a[i][j] = 0;
	//cin graph
	//oneself equal

	for(i = 0; i < V; i++)
		a[i][i]= 1;
	while(scanf("%d %d",&i, &j) ==2){
		if(i == j)
			break;
		printf("%d\t%d\n", i, j);
		a[i][j] = a[j][i] = 1;
	}
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

