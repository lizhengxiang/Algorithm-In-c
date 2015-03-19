//String search
#include<stdio.h>
#define N 1000
int main(){
	int i, j, t;
	char a[N], *p = "lizhengxiang";
	//read string
	for(i = 0; i < N-1; a[i] = t, i++)
		if((t = getchar()) == '?')
			break;
	a[i] = 0;
	// string search
	for(i = 0; a[i] != 0; i++){
		for(j = 0; p[j] != 0; j++)
			if(a[i+j] != p[j])
				break;
		//printf string find place
		if(p[j] == 0)
			printf("%d\t", i);
	}
	printf("\n");
	return 0;
}
