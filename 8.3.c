<<<<<<< HEAD
#include<stdio.h>
=======

>>>>>>> b10b9dec56617306ed20630b6126ca0a000d68c8
#define N 40
typedef int Item;

void merge(int *a, int l, int m, int r){
	int aux[N];
	int i, j, k;
	for(i = m+1; i > l; i--)
		aux[i-1] = a[i-1];
	for(j = m; j < r; j++)
		aux[r+m-j] = a[j+1];
	for(k = l; k < r; k++)
		a[k] = (aux[j] < aux[i])?aux[j--]:aux[i++];
}
void mergesort(Item *a, int l, int r){
	int m = (r+l) / 2;
	//printf("****");
	if(l >= r)
		return ;
	mergesort(a, l, m);
	mergesort(a, m+1, r);
	merge(a, l, m, r);

}

int main(){
	Item a[N];
	int i, j;
	for(i = 0; i < N/2; i++)
		a[i] = i;
	for(j = 0; i < N; i++)
		a[i] = j++;
	mergesort(a, 0, N-1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
