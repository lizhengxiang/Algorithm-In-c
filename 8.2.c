/*
This program merges without using sentinels by copying the second array into aux in
reverse order back to back with the first (putting aux in bitonic order). The first for loop
moves the first array and leaves i pointing to l, ready to begin the merge. The second for
loop moves the second array, and leaves j pointing to r. Then, in the merge (the third for
loop), the largest element serves as the sentinel in whichever array it is. The inner loop of
this program is short (move to aux, compare, move back to a, increment i or j, increment
and test k).
*/
#include<stdio.h>
#define N 100
void merge(int *a, int l, int m, int r){
	int aux[N];
	int i, j, k;
	for(i = m; i >= l; i--)
		aux[i] = a[i];
	for(j = m; j < r; j++)
		aux[r+m-j] = a[j+1];
	for(k = l; k < r; k++)
		a[k] = (aux[j] < aux[i])?aux[j--]:aux[i++];
}

int main(){
	int a[N];
	int i, j, m;
	for(i = 0; i < N/2; ++i)
		a[i] = i;
	m = i;
	for(j = 0; i < N; i++, j++)
		a[i] = j;
	merge(a, 0, m, N-1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");	
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
