/*
*Infix-to-postfix conversion
*s program is another example of a pushdown-stack client. In this case, 
*the stack contains characters. To convert (A+B) to the postfix form AB+, 
*we ignore the left parenthesis,convert A to postfix, save the + on the 
*stack, convert B to postfix, then, on encountering the right parenthesis, 
*pop the stack and output the +.			
*/			

#include<stdio.h>
#include<string.h>
#include"Stack_ADT.h"

int main(){
	char *a = "(5+(6+6)*(9+5))";
	int i, N = strlen(a);
	STACKinit(N);
	for(i = 0; i < N; i++){
		if(a[i] == ')')
			printf("%c\t", STACKpop());
		if(a[i] == '+' || a[i] == '*')
			STACKpush(a[i]);
		if(a[i] >= '0' && a[i] <= '9')
			printf("%c\t", a[i]);
	}
	printf("\n");
	return 0;
}
