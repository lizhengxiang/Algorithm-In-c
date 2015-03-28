/*
Write a recursive program that finds the maximum element in an array, based on
comparing the first element in the array against the maximum element in the rest of the array
(computed recursively
*/
#include<stdio.h>
#include<stdlib.h>

int Rand(){
	return  rand() % 1000;
}

int max(int *a, int i, int r){
	int u, v, m = (i +r) / 2;
	if(i == r)
		return a[i];
	u = max(a, i, m);
	v = max(a, m+1, r);
	if(u>v)
		return u; 
	return v;
}
int main(){
	int num[100], maxnum;
	int i;
	for(i = 0; i < 100; i++){
		num[i] = Rand();
	}
	//num[0] = 1000;
	maxnum = max(num, 1, 99);
	printf("%d\n", (num[0] > maxnum) ? num[0]: maxnum);
	return 0;
}
