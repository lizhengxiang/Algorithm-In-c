/*
If we do not use sentinels and then replace every occurrence of "1" by
"h" in insertion sort, the resulting program h-sorts the file. Adding an
outer loop to change the increments leads to this compact shellsort
implementation, which uses the increment sequence 1 4 13 40 121
364 1093 3280 9841 . . . .
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
	for(h = 1; h <= (r-1)/9; h = 3*h+1)
		;  //increment sequence
	for(; h > 0; h /= 3){
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
