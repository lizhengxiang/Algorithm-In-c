/*we might use the following code to multiply two matrices a and b, 
* leaving the result in a third matrix c
*/

#include<stdio.h>
#define N 3
int main(){
	int a[N][N], b[N][N], c[N][N];
	int i, j, k;
	//Init matrice
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			a[i][j] = i;
			b[i][j] = i;
			c[i][j] = 0;
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//multiply two matrices a and b, leaving the result in a third matrix c
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			for(k = 0; k < N; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
