/*
Explain how you would sort a deck of cards with the restriction that the cards must be
laid out face down in a row, and the only allowed operations are to check the values of two
cards and (optionally) to exchange them.
*/
#include<stdio.h>
#include<stdlib.h>
#define N 100

int Rand(){
	return rand() % 1000;
}

void sort(int *a, int m, int n){
	int i, j;
	int tag = 0;
	for(i = m; i < n; i++){
		tag = 0;
		for(j = 0; j < n - i; j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				tag = 1;
			}
		}
		if(!tag)
			break;
	}
}
int main(){
	int a[N];
	int i;
	for(i = 0; i < N; i++)
		a[i] = Rand();
	sort(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
