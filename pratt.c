#include<stdio.h>
#define N 10

int main(){
	int a[N];
	int i, j, m = 1, n = 0;
	a[0] = 1;
	for(j = 1; j < 4; j++){
		for(i = 0; i < j; i++){
			a[m++] = 2 * a[n++];
		}
		a[m++] = 3 * a[n-1]; 
	}
	for(i = 0; i < N; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
