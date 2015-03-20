/*
*Write a program that replaces substrings of more than one blank in a given string by
*exactly one blank.
*/
#include<stdio.h>
#include<string.h>

int main(){
	int i = 0, j = 0;
	char c;
	char a[100], b[100];
	//Init string
	while((c = getchar()) != '\n'){
		a[i++] = c;
	}
	a[i] = 0;
	//A space to replace multiple Spaces
	for(i = 0; a[i] != 0; i++){
		if(a[i] == ' '){
			b[j] = a[i];
			while(a[++i] == ' '){
				;
			}
			j++;
		}
		b[j] = a[i];
		j++;
	}
	b[j] = 0;
	i = 0;
	while(b[i] != 0)
		printf("%c", b[i++]);
	printf("\n");
}
