
#include<stdio.h>
int main(){
	int i, j = 0, k = 1, temp;
	for(i = 0; i < 10; i++){
		temp = j + k;
		j = k;
		k = temp;
		printf("%d\t", temp);
	}
	printf("\n");
	return 0;
}
