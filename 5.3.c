/*
Give the sequences of argument values that result when Program 5.2 is
invoked for each of the integers 1 through 9.
*/

#include<stdio.h>
#include<math.h>

int factorial(int N){
	if(N == 0)
		return 1;
	else
		return N * factorial(N - 1);
}

int main(){
	int N, M = 997;
	//scanf("%d", &N);
	for(N = 1; N < 10; N ++)
	printf("%d\n",factorial(N));
	return 0;
}
