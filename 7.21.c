/*
Are sentinel keys needed if insertion sort is called directly from within quicksort?
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int Item;
#define N 100000
Item Rand(){
	return rand() % 100000;
}
int less(Item a, Item b){
	return a > b;
}

void exch(Item *a, Item *b){
	Item temp = *a;
	*a = *b;
	*b = temp; 
}
//find right partition place
int partition(Item *a, int l, int r){
	int i = l-1, j = r;
	Item v = a[r];
	for( ; ; ){
		while(less(a[++i], v))
			;
		while(less(v, a[--j]))
			if(i == j)
				break;
		if(i >= j)
			break;
		exch(&a[i], &a[j]);
	}
	exch(&a[i], &a[r]);
	return i;
} 

void compexch(Item *a, Item *b){
	if(less(*a, *b))
		exch(a, b);
}
//insertion sort
void insertion(Item *a, int l, int r){
	int i;
	for(i = r; i > l; i--)
		compexch(&a[i-1], &a[i]);
	for(i = l + 2; i < r; i++){
		int j = i;
		Item v = a[i];
		while(less(v, a[j-1])){
			a[j] = a[j-1];
			j--;
		}
		a[j] = v;
	}
}
// quicksort
void quicksort(Item *a, int l, int r){
	if(r- l <= 9){
		insertion(a, l, r);
		return ;
	}
	//if(r <= l )
	//	return ;
	int i;
	i = partition(a, l, r);
	quicksort(a, l, i-1);
	quicksort(a, i+1, r);
}
int main(){
	clock_t start, finish;
	start = clock();
	Item a[N];
	int i;
	for(i = 0; i < N; i++)
		a[i] = Rand();
	quicksort(a, 0, N-1);
	for(i = 0; i < N; i++){
		//if(i % 10 == 0)
		//printf("\n");
		//printf("%d\t", a[i]);
	}
	printf("\n");
	finish = clock();
	double duration =(double)(finish - start) / CLOCKS_PER_SEC;
	printf("%0.7f\n", duration);
	return 0;
}
