/*
For each i from l to r-1, the inner (j) loop puts the minimum element among the
elements in a[i], . . ., a[r] into a[i] by passing from right to left through the
elements, compare–exchanging successive elements. The smallest one moves on all such
comparisons, so it "bubbles" to the beginning. As in selection sort, as the index i travels
from left to right through the file, the elements to its left are in their final position in the
array.
*/
#include<stdio.h>
#include<stdio.h>
#define N 100
typedef struct Node node;
struct Node{
	int data_1;
	int data_2;
};

int Rand(){
	return rand() % 1000;
}

int bubble(node *a, int l, int r){
	int i, j;
	for(i = l; i < r; i++)
		for(j = r; j > l; j--)
			if(a[j].data_1 > a[j-1].data_1){
				node temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
}

int main(){
	node a[N];
	int i;
	for(i = 0; i < N; i++){
		a[i].data_1 = Rand();
		a[i].data_2 = i;
	}
	bubble(a, 0, N);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%-3d + ", a[i].data_1);
		printf("%-2d      ", a[i].data_2);
	}
	printf("\n");
	return 0;	
}
