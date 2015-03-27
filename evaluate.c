/*
*Write a recursive program to evaluate postfix expressions.
*/
#include<stdio.h>
#include<string.h>
int i = 0, j = 0;
char a[30];

int main(){
	char c;
	while((c = getchar()) != '\n' )
		a[i++] = c;
		--i;
		j = i;
	printf("%d\n", eval());
}
int eval(){
	int x = 0;
	char b[10];
	int n = 0;
	while(a[j] == ' ' && j >= 0)
		--j;
	if(a[j] == '+' && j >= 0){
		j--;
	    return eval() + eval();
	}
	if(a[j] == '*' && j >= 0){
		--j;
		return eval() * eval();
	}
	while(a[j] >= '0' && a[j] <= '9')
		b[n++] = a[j--];
	--n;
	while(b[n] >= '0' && b[n] <= '9' && n >= 0)
		x = 10 * x + (b[n--] - '0');
	return x;
}
