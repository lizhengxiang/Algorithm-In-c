/*
*Write a program that takes a string as argument and reads a sequence of 
*words (sequences of characters separated by blank space) from standard 
*input, printing out thosethat appear as substrings somewhere in the 
*argument string.
*/

#include<stdio.h>
#include<string.h>

int main(){
	char a[100], b[1000], c;
	int i, j, temp = 0, n;
	//Init string
	printf("Init string\n");
	for(i = 0; (c = getchar()) != '\n'; i++)
		a[i] = c;
	a[i] = 0;
	//Init substring
	printf("Init substring\n");
	for(i = 0; (c = getchar()) != '\n'; i++)
		b[i] = c;
	b[i] = 0;
	//find substring
	for(i = 0, n = 0; a[i] != 0; i++){
		if(a[i] == ' ')
			i++;
			//n = i;
		printf("** %d\n", temp);
		for(j = temp; b[j] != 0 && b[j] != ' '; j++){
			if(a[i+j] != b[j])
				break;
			if(b[j+1] == ' '){
				printf("&&&&&\n");
				while(a[n] != ' ' && a[n] != 0){
					printf("%c", a[n++]);
				}
				temp = ++j + 1;
				printf("\n");
				
			}
			//if(a[i+j] != b[j])
			//	break;
		}
	}
}
