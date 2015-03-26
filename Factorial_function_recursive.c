#include<stdio.h>
/*
int factorial(int N){
	int i, temp = 1;
	for(i = 1; i <= N; i++)
		temp *= i;
	if(N)
		return temp;
	return 0; 
}
int main(){
	int i;
	for(i = 0; i < 10; i++){
		printf("%d !=  %d\n", i, factorial(i));
	}
	return 0;
}
*/
int main(){
	int i, temp = 1;
    for(i = 1; i < 10; i++){
		temp *= i;
    	printf("%d !=  %d\n", i, temp);
    }
    return 0;
}

