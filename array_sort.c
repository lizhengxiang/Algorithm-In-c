/*
Templates allow the implementation to be used to sort items of any data type for which
comparison and assignment are defined. The sort function here is a version of insertion
sort (see Section 6.3 for a detailed description, an example, and an improved
implementation). It uses a template function that compares two items and exchanges them
if necessary to make the second not < than the first.
*/

#include<stdio.h>
#include<stdlib.h>
#define N 1000
int Rand(){
	return rand() % 1000;
}
void sort(int *a, int i, int j){
	for(i = 1; i < N; i++)
		for(j = i; j >= 0; j--)
			if(a[j-1] > a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
}

int main(){
	int a[N], i;
	for(i = 0; i < N; i++)
		a[i] = Rand();
	sort(a, 0, N -1);
	for(i = 0; i < N; i++){
		printf("%d\t", a[i]);
		if(i % 10 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}
