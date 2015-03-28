/*
This program, although compact and elegant, is not usable because it takes exponential
time to compute F N . The running time to compute F N+1 is ø = 1.6 times as long as the
running time to compute F N . For example, since ø 9 > 60, if we notice that our computer
takes about a second to compute F N , we know that it will take more than a minute to
compute F N+9 and more than an hour to compute F N+18 .
*/

#include<stdio.h>

int F(int i){
	if(i < 1)
		return 0;
	if(i == 1)
		return 1;
	return F(i - 1) + F(i - 2);
}
int main(){
	int i;
	for(i = 0; i < 10; i++)
		printf("%d\t", F(i));
	printf("\n");
	return 0;
}
