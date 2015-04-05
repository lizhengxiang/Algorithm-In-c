/*
This code implements the overloaded operator< and the functions scan, rand, and
show that are declared in Program 6.9. Since the records are small structures, we can have
exch use the built-in assignment operator without undue worry about the expense of
copying items.
*/
#include"Item.h"
#include<stdio.h>
#include<stdlib.h>
double ITEMrand(void){
	return 1.0 * rend() / RAND_MAX;
}

int ITEMscan(double *x){
	return scanf("%f", x);
}

void ITEMshow(double x){
	printf("%7.5f", x);
}
