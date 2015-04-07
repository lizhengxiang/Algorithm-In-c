#include<stdio.h>
#include<stdlib.h>
#define N 100
#define M 4
int Rand(){
	return rand() % 3;
}
void distcount(int *a, int l, int r){
	int i,  j, cnt[M];
	int b[N];
	for(i = 0; i < M; i++){
		cnt[i] = 0;
	}
	for(i = 0; i < r; i++){
		cnt[a[i]+1]++;
	}
	for(i = 1; i < M; i++){
		cnt[i] += cnt[i-1];
	}
	for(i = 0; i < r; i++){
		b[cnt[a[i]]++] = a[i];
	}
	for(i = 0; i < r; i++){
		a[i] = b[i];
	}
	
}
int main(){
	int a[N], i;
	for(i = 0; i < N; i++)
		a[i] = Rand();
	distcount(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
