/*
*Give a class definition for Item that overloads the == operator 
*to support equality testing among floating-point numbers. Consider 
*two floating-point numbers to be equal if the absolute value of 
*their difference divided by the larger (in absolute value) of the 
*two numbers is less than 10 –6
*/

#include<stdio.h>
#include<math.h>
#include"Item.h"

int main(){
	float a, b;
	int i;
	scanf("%f %f", &a, &b);
	i = eq(a, b);
	if(i == 1)
		printf("equality\n");
	else
		printf("not equality\n");
	return 0;
}
