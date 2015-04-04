/*
Find the running time when you use shellsort with the increments 1 2 4 8 16 32 64 128 256
512 1024 2048 . . . to sort a file consisting of the integers 1,2,...,N in the odd positions and N +1,N
+2,...,2N in the even positions.
*/

#include<stdio.h>
#include<stdio.h>
#include<time.h>
#define N 10000
int Rand(){
	return rand() % 1000;
}

int less(int a, int b){
	return a > b;
}
int bubble(int *a, int l, int r){
	int i, j, h;
	for(h = 1; h <= r-1; h = 2*h)
		;  //increment sequence
	for(; h > 0; h /= 2){
		for(i = 1+h; i <= r; i++){
			int j = i;
			int v = a[i];
			while(j >= 1+h && less(v, a[j-h])){
				a[j] = a[j-h];
				j -= h;
			}
			a[j] = v;
		}
	}
}

int main(){
	 clock_t start, finish;  
	int a[N], i;
	start = clock();
	for(i = 0; i < N; i++){
		if(i % 2 == 0)
			a[i] = i+1;
		//a[i] = i;
		else
			a[i] = i;
	}
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
