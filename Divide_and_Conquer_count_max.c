/*
* This function divides an array a[l], . . . , a[r] into a[l], . . . ,
* a[m] and a[m+1], . . . , a[r], finds the maximum elements in the two
* parts (recursively), and returns the larger of the two as the maximum element
* in the whole array. It assumes that Item is a first-class type for which > is
* defined. If the array size is even, the two parts are equal in size; if the array
* size is odd, the sizes of the two parts differ by 1.
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
	int num[100];
	int i;
	for(i = 0; i < 100; i++){
		num[i] = Rand();
	}
	
	printf("%d\n", max(num, 0, 99));
	return 0;
}
