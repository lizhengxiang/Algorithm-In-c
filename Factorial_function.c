/*
* This recursive function computes the function N!, using the standard recursive definition. It
* returns the correct value when called with N nonnegative and sufficiently small that N! can
* be represented as an int.
*/

#include<stdio.h>

int factorial(int N){
	if(N == 0)
		return 1;
	return N * factorial(N-1);
}

int main(){
	int i;
	for(i = 0; i < 10; i++){
		printf("%d  !=  %d\n", i, factorial(i));
	}
	return 0;
}
