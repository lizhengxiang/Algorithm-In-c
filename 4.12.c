/*
*Extend your solution to Exercise 4.14 to include the unary operators - (negation) and $
*(square root). Also, modify the abstract stack machine in Program 4.5 to use floating point.
*For example, given the expression
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include"Stack_ADT.h"

int main(){
	char a[20], b[20], c;
	int N, i = 0, j = 0;
	while((c = getchar())!='\n'){
		b[i++] = c;	
	}
	b[i] = '\0';
	N = strlen(b);
	STACKinit(N);
	for(i = 0; i < N; i++){
		if(b[i] == '-' && b[i+1] >= '0' && b[i+1] <= '9'){
            a[j++] = b[i];
			continue;
		}

		if(b[i] == ')'){
			if(!STACKempty()){
				a[j++] = ' ';
				a[j++] = STACKpop();
				//a[j++] = ' ';
			}
		}
		if(b[i] == '+' || b[i] == '*'|| b[i] == '-' || b[i] == '/' || b[i] == '$'){
			STACKpush(b[i]);
			a[j++] = ' ';
		}
		if(b[i] >= '0' && b[i] <= '9'){
			a[j++] = b[i];
		}
		if(b[i] == '-' && b[i+1] >= '0' && b[i+1] <= '9')
			a[j++] = b[i];
	}
	a[j] = 0;
	printf("%s\n",a);
	for(i = 0; i < j; i++){
		if(a[i] == '+')
			STACKpush(STACKpop()+STACKpop());
		if(a[i] == '-' && a[i+1] <'0' && a[i+1] > '9'){
			int nu = STACKpop();
			STACKpush(STACKpop() - nu);
		}
		if(a[i] == '*')
			STACKpush(STACKpop()*STACKpop());
		if(a[i] == '/'){
            int nu = STACKpop();
            STACKpush(STACKpop()/nu);
			//printf("%d\n",nu);
        }
		if(a[i] == '$'){
			STACKpush(sqrt(STACKpop()));
		}
		if(a[i] >= '0' && a[i] <= '9'||a[i] == '-' && a[i+1] >= '0' && a[i+1] <= '9'){
			STACKpush(0);
			int x = 1;
			if(a[i] == '-'){
				x = -1;
				i++;
			}
	    	while(a[i] >= '0' && a[i] <= '9'){
            	STACKpush(10*STACKpop() + (a[i++] - '0'));
			}
			if(x == -1){
				STACKpush(x*STACKpop());
			}
		}
	}
	if(!STACKempty())
		printf("%0.8f\n", STACKpop());
}
