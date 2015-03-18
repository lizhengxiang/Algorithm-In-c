#include<stdio.h>
#include<stdlib.h>

//Define list struct 
typedef struct node* link;
struct node{
	int Item;
	link next;
};

//list reversal function
link reversal(link x){
	link r = NULL, t, y = x;
	while(y != NULL ){
		t = y->next;
		y->next = r;
		r = y;
		y = t; 
	}
	return r;
}

int main(){
	link x = malloc(sizeof *x), t;
	int i;
	t = x;
	x->Item = 0;
	//Init list
	for(i = 1; i < 100; i++){
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
