/*
*Write a program that converts a postfix experession to infix,
*using a pushdown stack
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef char Item;
#include"Stack_ADT.h"
#define N 20

int main(){
	Item a[20], b[20], c, k;
	int i , Num = 0, j;
	STACKinit(N);
	//printf("%d\n", strlen(a));
	while((c = getchar()) != '\n'){
		if(c >= '0' && c <= '9'){
			STACKpush(c);
			//printf("%c", c);
		}
		//printf("\n");
		if(c == '+' || c == '-' || c == '*' || c == '/'){
			k = c;
			i = 0, j = 0;
			if(STACKempty())
				while( c = STACKpop()){
					if(c == ')')
						++Num;
					if(c == '(')
						--Num;
					//printf("%c", c);
					a[i++] = c;
					if(Num == 0)
						break;
			}
			if(STACKempty()){
				while( c = STACKpop()){
					if(c == ')')
						++Num;
					if(c == '(')
						--Num;
					b[j++] = c;
					if(Num == 0)
						break; 
				}
			}
		
			STACKpush(')');
			while(--i != -1){
				//printf("%c", a[i]);
				STACKpush(a[i]);
			}
			STACKpush(k);
			while(--j != -1){
				STACKpush(b[j]);
			}
			STACKpush('(');	
		}
	}

	while(STACKempty())
		printf(" %c ", STACKpop());
	printf("\n");
	return 0;
}
