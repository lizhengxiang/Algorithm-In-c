/*
*Write a recursive program that removes the final node of a linked list.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node* link;
struct node{
	link next;
	int item;
};
//find last node and delete last node
link delete(link x){
	if(x->next->next = NULL){
		link t = x->next;
		free(x);
		return t;
	}
	x->next = delete(x->next);
	return x;
}
int main(){
	int i, j = 0;
	link t = malloc(sizeof *t), x = t, m;
	t->next = t;
	//Init link
	for(i = 0; i < 10; i++){
		x = (x->next = malloc(sizeof *t));
		x->item = i;
		printf("%d\t", x->item);
	}
	printf("\n");
	x->next = NULL;
	t = t->next;
	//printf link
	while(t->next != NULL){
		printf("%d\t", t->item);
		t = t->next;
	}
	printf("\n");
	return 0;
}
