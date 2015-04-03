/*
Show how to implement a shellsort with the increments 1 8 23 77 281 1073 4193 16577 . . .,
with direct calculations to get successive increments in a manner similar to the code given for
Knuth's increments.
*/
#include<stdio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 100
int Rand(){
	return rand() % 1000;
}

int less(int a, int b){
	return a > b;
} 
int bubble(int *a, int l, int r){
	int i, j, h;
	//printf("%d\n", pow(4,3));
	int n, b[N], m = 1;
	float temp_1, temp_2;
    b[0] = 1;
	//Step sequence
	printf("%d\t", b[0]);
    for(n = 0; n < N && b[n] <= N; n++){
         b[m] = 
		temp_1 = pow(4 , 1+n);
		temp_2 = 3 * pow(2, n);
		b[m++] = temp_1 + temp_2 + 1;
		printf("%d\t",b[m-1]);
		//break;
	}
	printf("\n\n");

	//printf ("%d\n", n);
	while(--n >= 0){
		//printf("\n****%d\n", n);
		h = b[n];
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
	int a[N];
	int i;
	// b[N];
	//b[0] = 1;
	//for(i = 1; i < N && a [i-2] <= N; i++)
	//	a[i+1] = pow(4 , i+1) + 3 * pow(2, i) + 1;

	start = clock();
	for(i = 0; i < N; i++){
		a[i] = Rand();
		//a[i].n = i;
	}
	bubble(a, 0, N);
	for(i = 1; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%3d\t ", a[i]);
		//printf("%3d\t", a[i].n);
	}
	finish = clock();
	printf("\n");
	float duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf("finish = %f\n", duration);
	return 0;	
}
