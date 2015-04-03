/*
Give diagrams corresponding to Figures 6.8 and 6.9 for the keys E A S Y Q U E S T I O N.
*/
#include<stdio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 12
int Rand(){
	return rand() % 1000;
}

int less(int a, int b){
	return a > b;
} 
int bubble(int *a, int l, int r){
	int i, j, h;
	int n, b[N], m = 1;
	float temp_1, temp_2;
    b[0] = 1;
	printf("%d\t", b[0]);
    for(n = 0; n < N && b[n] <= N; n++){
         b[m] = 
		temp_1 = pow(4 , 1+n);
		temp_2 = 3 * pow(2, n);
		b[m++] = temp_1 + temp_2 + 1;
		printf("%d\t",b[m-1]);
	}
	printf("\n\n");
	printf("The original sequence\n");
	for(i = 0; i < N; i++)
    	printf("%c\t",a[i]);
	printf ("\n");
	while(--n >= 0){
		h = b[n];
		for(i = l+h; i < r; i++){
			int j = i;
			int v = a[i];
			while(j >= l+h && less(v, a[j-h])){
				a[j] = a[j-h];
				j -= h;
			}
			a[j] = v;
			int temp;
			printf("%d sort:\t", h);
			for(temp = 0; temp < N; temp++){
				printf("%c\t", a[temp]);
			}
			printf("\n");
		}	
		printf("\n");
	}
}

int main(){
	 clock_t start, finish;  
	int a[N]={'E','A','S','Y','Q','U','E','S','T','I','O', 'N'};
	int i;
	start = clock();
	printf("\n");
	bubble(a, 0, N);
	for(i = 0 ; i < N; i++){
		printf("%c\t", a[i]);
	}
	finish = clock();
	printf("\n");
	float duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf("finish = %f\n", duration);
	return 0;	
}
