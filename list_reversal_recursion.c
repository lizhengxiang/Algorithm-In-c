/*
Write a recursive program for reversing the order of the nodes in a linked list
(see Program 3.7). Hint: Use a global variable.
*/
#include<stdio.h>
#include<stdlib.h>

//Define list struct 
typedef struct node* link;
struct node{
	int Item;
	link next;
};
link r = NULL;
//list reversal function
link reversal(link x){
	link y = x, h;
	if(y != NULL ){
		h = y->next;
		y->next = r;
		r = y;
		y = h; 
		reversal(y);
	}
	return r;
}

int main(){
	link x = malloc(sizeof *x), t;
	int i;
	t = x;
	x->Item = 0;
	//Init list
	for(i = 1; i < 10; i++){
		x = (x->next = malloc(sizeof *x));
		x->Item = i;
	}
	x->next = NULL;
	//list reversal
	t = reversal(t);
	//print list 99 98 97 ------
	while(t != NULL){
		printf("%d\t", t->Item);
		t = t->next;
	}
	printf("\n");
	return 0;
}
