/*
Templates allow the implementation to be used to sort items of any data type for which
comparison and assignment are defined. The sort function here is a version of insertion
sort (see Section 6.3 for a detailed description, an example, and an improved
implementation). It uses a template function that compares two items and exchanges them
if necessary to make the second not < than the first.

Give all sequences of three compare–exchange operations that will sort three elements
(see Program 6.1).
*/

#include<stdio.h>
#include<stdlib.h>
#define N 3
int Rand(){
	return rand() % 1000;
}
void sort(int *a, int i, int j){
	for(i = 1; i < N; i++){
		for(j = i; j >= 0; j--)
			if(a[j-1] > a[j]){
				//compare–exchange operations
				printf("%d\t%d\t\n", a[j], a[j-1]);
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				printf("%d\t%d\t", a[j], a[j-1]);
			}
		printf("\n");
	}
}

int main(){
	int a[N], i;
	for(i = 0; i < N; i++)
		a[i] = Rand();
	sort(a, 0, N -1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
