#include<stdio.h>
#include<string.h>
#include"STACK.h"

int main(){
	Item c;
	int N, j;
	Item a[20];
	scanf("%s",a);
	N = strlen(a);
	//printf("%d\n", N);
	STACKinit(N);
	
	//for(j = 0; j <= N; j++)
	//	printf("%c",a[j]);
	//printf("\n");
	for(j = 0; j <= N; j++){
		if(a[j] >= 'A' && a[j] <= 'Z'){
			STACKpush(a[j]);
			//printf("%c ", a[j]);
		}
		else if(a[j] == '.'){
			if(!STACKempty())
				printf("%c\t",STACKpop());
		}
	}
	printf("\n");
	return 0;
}
