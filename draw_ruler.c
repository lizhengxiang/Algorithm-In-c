/*
To draw the marks on a ruler, we draw the marks on the left half, then draw
the longest mark in the middle, then draw the marks on the right half. This
program is intended to be used with r – l equal to a power of 2—a property
that it preserves in its recursive calls (see Exercise 5.27).
*/

#include<stdio.h>

void marks(int i, int j){
	int n = 0;
	for(n = 0; n < i; n++)
		printf(" ");
	printf(" %d ", j);
}

void ruler(int l, int r, int h){
	int m = (l+r) / 2;
	if(h > 0){
		ruler(l, m, h-1);
		marks(m, h);
		ruler(m, r, h-1);
	}
}

int main(){
	int i;
	ruler(0, 8, 3);
	printf("\n");
	for(i = 0; i < 8; i++)
		printf("______");
	printf("\n");
	return 0;
}
