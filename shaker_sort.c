/*
For each i from l to r-1, the inner (j) loop puts the minimum element among the
elements in a[i], . . ., a[r] into a[i] by passing from right to left through the
elements, compare–exchanging successive elements. The smallest one moves on all such
comparisons, so it "bubbles" to the beginning. As in selection sort, as the index i travels
from left to right through the file, the elements to its left are in their final position in the
array.
////////////////////////////////////////////////////////////////////////////////////////
Implement a version of bubble sort that alternates left-to-right and right-to-left passes through
the data. This (faster but more complicated) algorithm is called shaker sort (see Figure 6.7).
*/
#include<stdio.h>
#include<stdio.h>
#include<time.h>
#define N 10000
int Rand(){
	return rand() % 1000;
}

int bubble(int *a, int l, int r){
	int i, j, m, teg;
	for(i = l; i < r; i++){
		teg = 1;
		for(j = r, m = l; j > l && m < r ; j--, m++)
			if(a[j] > a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				teg = 0;
			}
			if(a[m] > a[m+1]){
				int n = a[m];
				a[m] = a[m+1];
				a[m+1] = a[m];
				teg = 0;
			}
		if(teg)
			break;
	}
}

int main(){
	 clock_t start, finish;  
	int a[N], i;
	start = clock();
	for(i = 0; i < N; i++)
		a[i] = Rand();
	bubble(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	finish = clock();
	printf("\n");
	float duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf("finish = %f\n", duration);
	return 0;	
}
