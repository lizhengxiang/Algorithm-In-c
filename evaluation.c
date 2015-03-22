/*
*Postfix-expression evaluation
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Stack_ADT.h"

int main(){
	int N, i;
	char *a = "5 9 8 + 4 6 * * 7 + *";
	N = strlen(a);
	STACKinit(N);
	for(i = 0; i < N; i++){
		if(a[i] == '+')
			STACKpush(STACKpop() + STACKpop());
		if(a[i] == '*')
			STACKpush(STACKpop() * STACKpop());
		if(a[i] >= '0' && a[i] <= '9')
			STACKpush(0);
		while(a[i] >= '0' && a[i] <= '9')
			STACKpush(10*STACKpop() + (a[i++] - '0'));
	}
	printf("%d\n", STACKpop());
	return 0;
	

}
