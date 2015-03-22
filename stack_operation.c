/*
*A letter means push and an asterisk means pop in the sequence
*/

#include<stdio.h>
#include"Stack_ADT.h"

int main(){
	Item c;
	Item stack[10];
	//STACKinit(10);
	while((c = getchar()) != '\n'){
		if(c >= 'a' && c <= 'z')
			STACKpush(c);
		if(c == '*')
			if(STACKempty())
				printf("%c\t", STACKpop());
			else
				printf("stack empty\n");
	}
	printf("\n");
	return 0;
	
}
