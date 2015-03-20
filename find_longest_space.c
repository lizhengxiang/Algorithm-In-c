/*
*Write an efficient program that finds the length of the longest sequence of blanks in a
*given string, examining as few characters in the string as possible. Hint: Your program
*should become faster as the length of the sequence of blanks increases.
*/

#include<stdio.h>		
#include<string.h>		
		
int main(){		
	char a[100], c;		
	int i, Num = 0, t = 0;		
	//Init string		
	printf("Init string\n");		
	for(i = 0; (c = getchar()) != '\n'; i++)		
		a[i] = c;		
	a[i] = 0;
	for(i = 0; a[i] != 0; i++){
		if(a[i] == ' '){
			if(a[i + Num] == ' '){
				t = 0;
				while(a[++i] == ' ')
					++t;
				Num = t;			
			}
			else
				i += Num;
		}
	}
	printf("%d\n", Num);
}
