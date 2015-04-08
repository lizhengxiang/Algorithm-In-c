/*
About how many comparisons will quicksort (Program 7.1) make when sorting a file
consisting of N items that have just two different key values (k items with one value, N - k
items with the other)?
*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
int Num = 0;
int Rand(){
	return rand() % 2;
}

int less(int a, int b){
	return a < b;
}

void exch(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;		
	++Num;
}

int partition(int *a, int l, int r){
	int i = l-1, j = r, v = a[r];
	for(;;){
		while(less(a[++i], v))
			;
		while(less(v, a[--j]))
			if(l == j)
				break;
		if(i >= j)
			break;
		exch(&a[i], &a[j]);
	}
	exch(&a[i], &a[r]);
	return i;

}

void quicksort(int *a, int l, int r){
	if(l >= r)
		return ;
	int i = partition(a, l, r);
	quicksort(a, l, i-1);
	quicksort(a, i+1, r);
}

int main(){
	int a[N], i;
	for(i = 0; i < N; i++)
		a[i] = Rand();	
	quicksort(a, 0, N-1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	printf("max exchange %d\n",Num);
	return 0;
}
