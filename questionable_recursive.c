/*
*If the argument N is odd, this function calls itself with 3N + 1 as an argument; if N is even,
*it calls itself with N/2 as an argument. We cannot use induction to prove that this program
*terminates, because not every recursive call uses an argument smaller than the one given.
*/

#include<stdio.h>
int puzzle(int N){
	if(N == 1)
		return 1;
	if(N % 2 == 0)
		return puzzle(N/2);
	else
		return puzzle(3*N+1);
}
int main(){
	int i;
	for(i = 19; i < 20000000; i *= 13){
		printf("%d\t%d\n", i, puzzle(i));
	}
	return 0;
}
