/*
*Sorting an array of strings
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Nmax 5
#define Mmax 100
char buf[Mmax];
int M = 0;

int compare(void *i, void *j){
	return strcmp(*(char **)i, *(char **)j);
}

int main(){
	int i, N;
	char *a[Nmax];
	for(N = 0; N < Nmax; N++){
		a[N] = &buf[M];
		
		scanf("%s", a[N]);
		a[strlen(a[N])] = 0;
		M += strlen(a[N])+1;
	}
	printf("\n");
	//Sorting an arry of strings
	qsort(a, N, sizeof(char *), compare);
	for(i = 0; i < N; i++)
		printf("%s\n", a[i]);
	return 0;
}
