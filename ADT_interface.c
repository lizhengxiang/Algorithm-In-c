#include<stdio.h>
#include"ADT_interface.h"

int main(){
	int p, q, N = 10;
	UFinit(N);
	while(scanf("%d %d", &p, &q) == 2){
		if(!UFfind(p, q)){
			UFunion(p, q);
			printf("%d\t%d\n", p, q);
		}
	}
	return 0;
}
