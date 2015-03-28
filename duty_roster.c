#include<stdio.h>
int main(){
	int N = 31;
	int i, j = 0, k = 1;
	printf("\t******\n");
	printf("\t* ");
	for(i = 8; i <= N; i++){
		j++;

		if(k != 0){
			printf("%-2d", i);
			printf(" * ");
		}
		else
			printf("\t%-2d", i);
		k = 0;
		if(j % 5 == 0){
			printf("\n");
			printf("\t* ");
			k++;
		}

	}
	printf("\n");
	printf("\t******\n");
	printf("\n");

}
