/*
*Write a recursive program to compute lg(N!).
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
	int N;
	scanf("%d", &N);
	printf("%0.2f\n",log(factorial(N)) / log(10));
	return 0;
}
