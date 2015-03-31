/*
This code is an improvement over the implementation of sort in Program 6.1 because (i)
it first puts the smallest element in the array into the first position, so that that element can
serve as a sentinel; (ii) it does a single assignment, rather than an exchange, in the inner
loop; and (iii) it terminates the inner loop when the element being inserted is in position.
For each i, it sorts the elements a[l], . . ., a[i] by moving one position to the right
elements in the sorted list a[l], . . ., a[i-1] that are larger than a[i], then putting
a[i] into its proper position.
*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
int Rand(){
	return rand() % 1000;
}

int less(int a, int b){
	if(a > b)
		return 0;
	else
		return 1;
}
void sort(int *a, int l, int r){
	int i;
	for(i = r-1; i > l; i--){
		if(a[i-1] > a[i]){
			int temp = a[i];
			a[i] = a[i-1];
			a[i-1] = temp;
		}
	}
	for(i = l+2; i < r; i++){
		int j = i;
		int v = a[i];
		while(less(v, a[j-1])){
			a[j] = a[j-1];
			j--;
		}
		a[j] = v;
	}
}

int main(){
	int i, a[N];
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
