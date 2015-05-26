#include<stdio.h>
#define N 12
typedef char Item;

void merge(Item *a, int l, int m, int r){
	Item aux[N];
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
	if(l >= r)
		return ;
	mergesort(a, l, m);
	mergesort(a, m+1, r);
	merge(a, l, m, r);

}

int main(){
	Item a[N] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'};
	int i, j;
	mergesort(a, 0, N-1);
	for(i = 0; i < N; i++){
		printf("%C\t", a[i]);
	}
	printf("\n");
	return 0;
}
