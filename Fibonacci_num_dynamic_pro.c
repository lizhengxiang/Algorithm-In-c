/*
By saving the values that we compute in a static array (whose entries are initialized to 0 in
C++), we explicitly avoid any recomputation. This program computes F N in time
proportional to N, in stark contrast to the O(ø N ) time used by Program 5.10.
*/

#include<stdio.h>
static int a[20];

int Fibonacci(int i){
	int f;
	if(a[i] != 0)
		return a[i];
	if(i == 0)
		return 0;
	if(i == 1)
		return 1;
	if(i > 1)
		f = Fibonacci(i - 1) + Fibonacci(i - 2);
	return a[i] = f;	

}

int main(){
	int i;
	for(i = 0; i < 20; i++)
		a[i] = 0;
	for(i = 0; i < 10; i++)
		printf("%d\t", Fibonacci(i));
	printf("\n");
	return 0;
	

}
