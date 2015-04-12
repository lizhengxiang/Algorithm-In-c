/*
To combine two ordered arrays a and b into an ordered array c, we use a for loop that
puts an element into c at each iteration. If a is exhausted, the element comes from b; if b is
exhausted, the element comes from a; and if items remain in both, the smallest of the
remaining elements in a and b goes to c. Beyond the implicit assumption that the arrays
are ordered, this implementation assumes that the array c is disjoint from (that is, does not
overlap or share storage with) a and b.
*/

#include<stdio.h>
#include<stdlib.h>
#define N 20
#define M 20

int c[M+N];
void merging(int *a, int *b, int m, int n){
	int i, j, k;
	for(i = 0, j = 0, k = 0; k <= m+n; k++){
		if(i-1 == m || j-1 == n)
			break;
		c[k] = (a[i]<b[j])?a[i++]:b[j++];
	}
	if(i >= m)
		while(j <= n)
			c[k++] = b[j++];
	else
		while(i <= m)
			c[k++] = a[i++];
	for(i = 0; i < k; i++)
}

int main(){
	int a[N];
	int b[M];
	int i;
	
	for(i = 0; i < N; i++){
		a[i] = i + 1;
		b[i] = i + 5;
	}
	merging(a, b, M-1, N-1);
	for(i = 0; i < M + N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", c[i]);
	}
	printf("\n");
	return 0;
}
