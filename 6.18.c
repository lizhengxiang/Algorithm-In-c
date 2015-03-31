/*
Is insertion sort stable?
*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
int Rand(){
	return rand() % 100;
}
typedef struct Node node;
struct Node{
	int m;
	int n;
};

void sort(node *a, int l, int r){
	int i, j;
	for(i = l+1; i < r; i++){
		node v ;
		for(j = i; j > l; j--)
			if(a[j].m < a[j-1].m){
				v = a[j]; 
				a[j] = a[j-1];
				a[j-1] = v;
			}else{
				break;
			}
		//a[j-1] = a[i];
	}			//break;
	
}
int main(){
	int i;
	node a[N];
	for(i = 0; i < N; i++){
		a[i].m = Rand();
		a[i].n = i;
	}
	sort(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 5 == 0)
			printf("\n");
		printf("%-4d+", a[i].m);
		printf("%4d\t", a[i].n);
	}
	printf("\n");
	return 0;
}
