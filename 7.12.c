/*
This nonrecursive implementation (see Chapter 5) of quicksort uses an explicit pushdown
stack, replacing recursive calls with stack pushes (of the parameters) and the procedure
call/exit with a loop that pops parameters from the stack and processes them as long as the
stack is nonempty. We put the larger of the two subfiles on the stack first to ensure that the
maximum stack depth for sorting N elements is lg N (see Property 7.3).

Answer Exercise 7.11 for the case where we always push the right subfile, then the
left subfile (as is the case in the recursive implementation).
*/

#include<stdio.h>
#include<stdlib.h>
#define N 12
typedef char Item;
int *stack;
int n = 0;
int count = -1;
void STACKinit(){
	stack = malloc(N * sizeof(Item));
}

void STACKpush(Item num){
	stack[n++] = num;
	if(count < n)
		count = n;
}

Item STACKpop(){
	return stack[--n];
}

int STACKempty(){
	if(n == 0)
		return 1;
	return 0;
}

int Rand(){
	return rand()%100;
}
void push(int l, int r){
	STACKpush(r);
	STACKpush(l);
}

int less(Item a, Item b){
	return a < b;
}

void exch(Item *a, Item *b){
	Item temp = *a;
	*a = *b;
	*b = temp;
}

int partitin(Item *a, int l, int r){
	int i = l-1, j = r;
	Item v = a[r];
	for(;;){
		while(less(a[++i], v))
			;
		while(less(v, a[--j]))
			if(j == l)
				break;
		if(i >= j)
			break;
		exch(&a[i], &a[j]);
	}
	exch(&a[i], &a[r]);
	return i;
}
void quicksort(Item *a, int l, int r){
	int i;
	STACKinit();
	push(l, r);
	printf("Example of internal stack dynamics:\n");
	while(!STACKempty()){
		l = STACKpop();
		r = STACKpop();
		if(r <= l)
			continue;
		i = partitin(a, l, r);
		//if(i - l > r - l){
			push(l, i-1);
			push(i+1, r);
		//}else{
		//	push(i+1, r);
		//	push(l, i-1);
		//}
		int Num = 0;
		for(Num = 0; Num < n; Num++)
			printf("%c\t", a[Num]);
		if(Num)
			printf("\n");
	}
}

int main(){
	Item a[N] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'};
	int i;
	printf("Init data:\n");
	for(i = 0; i < N; i++)
		printf("%c\t", a[i]);
	printf("\n");
	quicksort(a, 0, N-1);
	printf("Sort finish:\n");
	for(i = 0; i < N; i++){
		//if(i % 10 == 0)
		//	printf("\n");
		printf("%c\t", a[i]);
	}
	printf("\n");
	printf("STAC max depth : %d\n", count);
	return 0;
}
