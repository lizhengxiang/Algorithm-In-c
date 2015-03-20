/*
* Write a program that takes a string as argument, and that prints out a table giving, for
* each character that occurs in the string, the character and its frequency of occurrence.
*/

#include<stdio.h>
#include<string.h>

int main(){
	int a[26], i;
	float num = 0.0;
	char c;
	for(i = 0; i < 26; i++)
		a[i] = 0;
	//count character occurrence number
	while((c = getchar()) != '\n'){
		if(c >= 'a' && c <= 'z'){
			a[c - 'a']++;
			num++;
		}
	}
	//count character frequence of occurrence
	for(i = 0; i < 26; i++)
		printf("%c\t%0.4f\n", 'a' + i, a[i]/num);
	return 0;
}
