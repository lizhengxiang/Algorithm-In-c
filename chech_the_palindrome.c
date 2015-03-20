/*Write a program that checks whether a given string is a palindrome (reads the same
*backward or forward), ignoring blanks. For example, your program should report success for
*the string if i had a hifi.
*/

#include<stdio.h>
#include<string.h>

int main(){
	char a[100], c;
	int i, j;
	//Init string char
	for(i = 0; (c = getchar())!='\n'; i++)
		a[i] = c;
	j = i-1;
	i = 0;
	//Determine whether palindrome
	while(j >= i){
		if(a[i] == ' ')
			i++;
		if(a[j] == ' ')
			j--;
		if(a[i++] != a[j--])
			break;
	}
	if(i >= j)
		printf("is palindrome\n");
	else
		printf("is not palindrome\n");
	
}
