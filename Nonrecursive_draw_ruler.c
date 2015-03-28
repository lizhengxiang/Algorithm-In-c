/*
In contrast to Program 5.8, we can also draw a ruler by first drawing all the
marks of length 1, then drawing all the marks of length 2, and so forth. The
variable t carries the length of the marks and the variable j carries the number
of marks in between two successive marks of length t. The outer for loop
increments t and preserves the property j = 2 t–1 . The inner for loop draws all
the marks of length t.
*/

#include<stdio.h>
int a[32];
void ruler(int l, int r, int h){
	int i, j, t;
	for(t = 1, j = 1; t <= h; t++, j += j)
		for(i = 0; l+j+i <= r; i += j+j)
			printf("%d ", a[l+j+i] = t);
}
void marks(int n, int h){
	int i;
	while(h >= 1){
		for(i = 0; i <= n; i++){
			if(a[i] >= h)
				printf(" | ");
			else
				printf("   ");
		}
		printf("\n");
		h--;
	}
}

int main(){
	int i;
	ruler(0, 32, 5);
	printf("\n");
	marks(32, 5);
	//printf("\n");
	for(i = 0; i < 32; i++)
		printf("___");
	printf("\n");
	return 0;
}
