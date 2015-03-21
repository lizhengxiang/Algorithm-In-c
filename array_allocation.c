/*
*Two-dimensional array allocation 
*This function dynamically allocates the memory for a two-dimensional 
*array, as an array of arrays. We first allocate an array of pointers, 
*then allocate memory for each row. With thisfunction, the statement
*/

#include<stdio.h>
#include<stdlib.h>
//Two-dimensional array allocatin
int **malloc2d(int m, int n){
	int i;
	int **t = malloc(m * sizeof(int*));
	for(i = 0; i < m; i++){
		t[i] = malloc(n * sizeof(int));
	}
	return t;
}

int main(){
	int i, j, M = 3, N = 5;
	int **array;
	array = malloc2d(M, N);
	//Init two dimentsional and print two dimentsional
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			array[i][j]	= i*j;
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
