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
