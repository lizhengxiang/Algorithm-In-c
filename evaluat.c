#include<stdio.h>
#include<string.h>
int i = 0, j = 0, x = 0;
char a[30];

int main(){
	char c;
	while((c = getchar()) != '\n' )
		a[i++] = c;

	printf("%d\n", eval());
}
int eval(){
	x = 0;
	while(a[j] == ' ' && j < i)
		++j;
	if(a[j] == '+' && j < i){
		j++;
	    return eval() + eval();
	}
	if(a[j] == '*' && j < i){
		++j;
		return eval() * eval();
	}
	while(a[j] >= '0' && a[j] <= '9')
		x = 10 * x + (a[j++] - '0');
	//printf("%d\n", x);
	return x;
}
