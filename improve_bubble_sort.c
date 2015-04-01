/*
For each i from l to r-1, the inner (j) loop puts the minimum element among the
elements in a[i], . . ., a[r] into a[i] by passing from right to left through the
elements, compare–exchanging successive elements. The smallest one moves on all such
comparisons, so it "bubbles" to the beginning. As in selection sort, as the index i travels
from left to right through the file, the elements to its left are in their final position in the
array.
*/
#include<stdio.h>
#include<stdio.h>
#define N 100
int Rand(){
	return rand() % 1000;
}

int bubble(int *a, int l, int r){
	int i, j;
	for(i = l; i < r; i++){
		int n = 1;
		for(j = r; j > l; j--)
			if(a[j] > a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				n = 0;
			}
		if(n)
			break;
	}
}

int main(){
	int a[N], i;
	for(i = 0; i < N; i++)
		a[i] = Rand();
	bubble(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;	
}
