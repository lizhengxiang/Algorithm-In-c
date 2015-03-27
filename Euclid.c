/*
*One of the oldest-known algorithms, dating back over 2000 years, is not this recursive method
*for finding the greatest common divisors of two integers.
*/

#include<stdio.h>

int gcd(int m, int n){
/*	if(n == 0)
		return m;
	return gcd(n, m % n);
*/
	while(n != 0){
		int temp = m;
		m = n;
		n = temp % n;
	}
	return m;
}

int main(){
	int i, j;
	for(i = 0; i < 10; i++)
		for(j = 0; j < 10; j++)
			printf("i = %d\tj = %d\t%d\n", i, j, gcd(i, j));
	return 0;
}
