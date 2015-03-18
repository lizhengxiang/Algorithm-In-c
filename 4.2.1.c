#include<stdio.h>
#include<string.h>
#include"STACK1.h"

int main(){
	char a[30], c;
	int j = 0;
	while((c = getchar()) != '#'){
		a[j++] = c;
	}
	a[j] = '\0';
	int i, N = strlen(a);
	STACKinit(N);
	printf("%s\n",a);
	for(i = 0; i < N; i++){
		if(a[i] == '+')
			STACKpush(STACKpop()+STACKpop());
		if(a[i] == '*')
			STACKpush(STACKpop()*STACKpop());
		if(a[i] >= '0' && a[i] <= '9')
			STACKpush(0);
		while(a[i] >= '0' && a[i] <= '9'){
			STACKpush(10*STACKpop()+(a[i++] - '0'));
		}
	}
	printf("%d\n",STACKpop());
	return 0;
}	
