/*
As we warned about the recursive solution to the problem of computing the Fibonacci
numbers, do not use this program, because it will take exponential time and therefore may
not ever run to completion even for small problem
*/

#include<stdio.h>
int N = 5;
//Item items[5];

typedef struct{
	int size;
	int val;
}Item;
Item items[5];
int knap(int cap){
	int i, space, max, t;
	for(i = 0, max = 0; i < N; i++){
		if((space = cap - items[i].size) > 0)
			if((t = knap(space) + items[i].val) > max){
				max = t;
				//printf("%d\t", items[i].val);
			}
		//printf("\n");
	}
	return max;
}
//int N = 5;
//Item items[5];
int main(){
	items[0].size = 3;
	items[0].val = 4;
	items[1].size = 4;  
	items[1].val = 5;
	items[2].val = 10;
	items[2].size = 7; 
	items[3].val = 11;
	items[3].size =  8;
	items[4].val = 13;
	items[4].size =  9;
	printf("%d\n", knap(17));
	return 0;
}
