#include<stdio.h>
#include<string.h>
typedef char Item;
#include"Stack_ADT.h"

int main(){
	int i = 0, j = 0, b[j], k, m = 0;;
	Item a[20], c, t;
	STACKinit(20);
	while( (c = getchar()) != '?'){
		if(c != '(' && (t = getchar()) == '=' && c >= 'a' && c <= 'z'){
			for(j = 0; j < i; j += 2 ){
				if(a[j] == c){
					b[m++] = a[j-1];
					break;
				}
			}
			//STACKpush(k);
			if(j >= i){
				a[i++] = c;
				printf("%c\n", a[--i]);
			}
			while((c = getchar()) != '\n'){
				if(c >= '0' && c <= '9')
					b[m++] = c - '0';
				if(c == '+' || c == '*')
					STACKpush(c);
				if(c == ')'){
					if(STACKempty()){
						if(STACKpop() == '+')
							k = b[--m] + b[--m];
						if(STACKpop() == '*')
							k = b[--m] * b[--m];
						if(STACKpop() == '='){
							a[i++] = k + '0';
							printf("%c\n", a[i-1]);
						}
					}
					//else
						//a[i++] = b[--j] + '0';
				}
			}
			if(m == 0){
				a[i++] = b[m] + '0';
				printf("%c\n", a[i-1]);	
			}
		}
		else if(c != '('){
			if(c >= 'a' && c <= 'z')
				for(k = 0; k < i; k+= 2)
					if(a[k] == c)
						printf("%c", a[k+1]);
			
			if(c == ')')
				printf("%c\t", STACKpop());
			if(c == '+' || c == '*'|| t == '+' || t == '*')
				STACKpush(c);
			if(c >= '0' && c <= '9')
				printf("%c\t", c);
		}
	}
	printf("\n");
	return 0;
}
