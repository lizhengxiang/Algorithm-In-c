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
	return rand() % 10000;
}

int less(int a, int b){
	if(a > b)
		return 0;
	else
		return 1;
}
void sort(int *a, int l, int r){
	int i, j;
	for(i = l+1; i < r; i++){
		int v ;
		for(j = i; j > l; j--)
			if(a[j] < a[j-1]){
				v = a[j]; 
				a[j] = a[j-1];
				a[j-1] = v;
			}else{
				break;
			}
		//a[j-1] = a[i];
	}			//break;
	
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
