/*
If the array has one or fewer elements, do nothing. Otherwise, the array is processed by a
partition procedure (see Program 7.2), which puts a[i] into position for some i
between l and r inclusive, and rearranges the other elements such that the recursive calls
properly finish the sort.

What is the maximum number of times during the execution of quicksort that the
largest element can be moved, for a file of N elements?
*/
#include<stdio.h>
#include<stdlib.h>
#define N 1600
int n = 0;
int MAX = -1;
int Rand(){
	return rand() % 1000;
}

int less(int a, int b){
	return a < b;
}

void exch(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	if(*a == MAX || *b == MAX)
		++n;
}
/*
The variable v holds the value of the partitioning element a[r], and i and j are the left
and right scan pointers, respectively. The partitioning loop increments i and decrements j,
while maintaining the invariant property that no elements to the left of i are greater than v
and no elements to the right of j are smaller than v. Once the pointers meet, we complete
the partitioning by exchanging a[i] and a[r], which puts v into a[i], with no larger
elements to v's right and no smaller elements to its left.
The partitioning loop is implemented as an infinite loop, with a break when the pointers
cross. The test j == l protects against the case that the partitioning element is the
smallest element in the file.
*/
int partition(int *a, int l, int r){
	int i = l-1, j = r, v = a[r];
	while(1){
		while(less(a[++i], v)) ;
		while(less(v, a[--j]))
			if(l == j)
				break;
		if(i >= j)
			break;
		if (j == i-1);
			exch(&a[i], &a[j]);
	}
	//a[i] = v;
	exch(&a[i], &a[r]);
	//printf(" *%d* ", i);
	return i;
}
void quicksort(int *a, int l, int r){
	int i;
	if(r <= l)
		return ;
	i = partition(a, l, r);
	quicksort(a, l, i-1);
	quicksort(a, i+1, r);
}

int main(){
	int a[N], i;
	for(i = 0; i < N; i++){
		a[i] = Rand();
		//printf("%d\t", a[i]);
		if(a[i] > MAX)
			MAX = a[i];
	}
	quicksort(a, 0, N-1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	printf("MAX = %d Number Exchange %d: \n", MAX, n);
	return 0;
}

