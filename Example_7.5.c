#include<stdio.h>
#include<stdlib.h>
typedef int Item;
#define N 100

Item Rand(){
	return rand() % 1000;
}

int eq(Item a, Item b){
	return a==b;
}

void exch(Item *a, Item *b){
	Item temp = *a;
	*a = *b;
	*b = temp;
}

int less(Item a, Item b){
	return a > b;
}
void quicksort(Item *a, int l, int r){
	int i, j, k, p, q;
	Item v;
	if(r <= l)
		return ;
	v = a[r], i = l-1, j = r, p = l-1, q = r;
	for( ; ; ){
		while(less(a[++i], v));
		while(less(v, a[--j]))	
			if(i == j)			
				break;
		if(i >= j)
			break;
		exch(&a[i], &a[j]);
		if(eq(a[i], v)){
			++p;
			exch(&a[p], &a[i]);
		}
		if(eq(v, a[j])){
			q--;
			exch(&a[q], &a[j]);
		}
	}
	exch(&a[i], &a[r]);
	j = i-1;
	i = i+1;
	for(k = l; k < p; k++, j--)
		exch(&a[k], &a[j]);
	for(k = r-1; k > q; k--, i++)
		exch(&a[k], &a[i]);
	quicksort(a, l, j);
	quicksort(a, i, r);

}

int main(){
	Item a[N];
	int i;
	for(i = 0; i < N; i++)
		a[i] = Rand();
	quicksort(a, 0, N-1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
