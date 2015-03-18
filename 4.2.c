#include<stdio.h>
#include<string.h>
#include"STACK1.h"

int main(){
	char a[20], b[20];
	int N, i, j = 0;
	scanf("%s", b);
	N = strlen(b);
	STACKinit(N);
	for(i = 0; i < N; i++){
		if(b[i] == ')')
		a[j++] = STACKpop();
		if(b[i] == '+' || b[i] == '*'|| b[i] == '-' || b[i] == '/')
			STACKpush(b[i]);
		if(b[i] >= '0' && b[i] <= '9')
			a[j++] = b[i];
	}
	a[j] = 0;
	printf("%s\n",a);
	for(i = 0; i < j; i++){
		if(a[i] == '+')
			STACKpush(STACKpop()+STACKpop());
		if(a[i] == '-'){
			int nu = STACKpop();
			STACKpush(STACKpop() - nu);
		}
		if(a[i] == '*')
			STACKpush(STACKpop()*STACKpop());
		if(a[i] == '/'){
            int nu = STACKpop();
            STACKpush(STACKpop()/nu);
			printf("%d\n",nu);
        }

		if(a[i] >= '0' && a[i] <= '9')
			STACKpush(a[i] - '0');
	}
	if(!STACKempty())
		printf("%0.8f\n", STACKpop());
}
