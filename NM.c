/*
*Modify Program 5.1 to compute N! mod M, such that overflow is no longer an
issue. Try running your program for M = 997 and N = 10 3 , 10 4 , 10 5 , and
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
	for(N = 10; N < 1000; N *= 5)
	printf("%d\n",factorial(N) % M);
	return 0;
}
