/*
For each i from l to r-1, exchange a[i] with the minimum element in a[i], . . . ,
a[r]. As the index i travels from left to right, the elements to its left are in their final
position in the array (and will not be touched again), so the array is fully sorted when i
reaches the right end.
*/
#include<stdio.h>
#include<stdlib.h>
#define N 20
int Rand(){
	return rand() % 1000;
}

void selection(int *a, int l, int r){
	int i, j, min;
	for(i = l; i < r; i++){
		min = i;
		for(j = i+1; j < r; j++){
			if(a[min] > a[j]){
				int temp = a[min];
				a[min] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(){
	int i;
	int a[N];
	for(i = 0; i < N; i++)
		a[i] = Rand();
	selection(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
