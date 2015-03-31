/*
Is selection sort stable?
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

void selection(node *a, int l, int r){
	int i, j, min;
	for(i = l; i < r; i++){
		min = i;
		for(j = i+1; j < r; j++){
			if(a[min].m > a[j].m){
				node temp;
				temp = a[min];
				a[min]= a[j];
				a[j] = temp;
			}
		}
	}
}

int main(){
	int i;
	node a[N];
	for(i = 0; i < N; i++){
		a[i].m = Rand();
		a[i].n = i;
	}
	selection(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 5 == 0)
			printf("\n");
		printf("%-4d+", a[i].m);
		printf("%4d\t", a[i].n);
	}
	printf("\n");
	return 0;
}
