/*
The array data[0], . . . , data[N-1] is to be rearranged in place as directed by
the index array a[0], . . ., a[N-1]. Any element with a[i] == i is in place
and does not need to be touched again. Otherwise, save data[i] as v and work through
the cycle a[i], a[a[i]], a[a[a[[[i]]], and so on, until reaching the index i again.
We follow the process again for the next element which is not in place, and continue in this
manner, ultimately rearranging the entire file, moving each record only once.
*/

#include<stdio.h>
#include<stdlib.h>
#define N 10
int Rand(){
	return rand() % 1000;
}

void inistu(int *data, int *a, int l, int r){
	int i, j, k;
	for(i = 0; i < r; i++){
		int v = data[i];
		for(k = i; a[k] != i; k = a[j], a[j] = j){
			j = k;
			data[k] = data[a[k]];
			//printf("JJJJ");
		}
		data[k] = v; 
		a[k] = k;
	}

}

int main(){
	int i;
	int a[N], b[N];
	//Init array
	for(i = 0; i < N; i++){
		a[i] = Rand();
		b[i] = a[i];
		printf("%d\t", a[i]);
	}
	printf("\n");
	inistu(a, b, 0, N);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
