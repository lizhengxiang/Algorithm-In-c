/*
A child's sorting toy has i cards that fit on a peg in position i for i from 1 to 5. Write
down the method that you use to put the cards on the pegs, assuming that you cannot tell
from the card whether it fits on a peg (you have to try fitting it on).
*/

#include<stdio.h>
#include<stdlib.h>
#define N 10

int Rand(){
	return rand() % 6;
}
int main(){
	int i, j;
	int a[N];
	for(i = 0; i < N; i++)
		a[i] = Rand();
	for(i = 1; i < 6; i++){
		printf("i : %d\t", i);
		for(j = 0; j < N; j++)
			if(a[j] == i)
				printf("%d\t", a[j]);
		printf("\n");
	}

}
