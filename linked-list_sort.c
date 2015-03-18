#include<stdio.h>
#include<stdlib.h>

//Define list
typedef struct node* link;
struct node{
	int Item;
	link next;
};

int main(){
	link x = malloc(sizeof *x), head_a = x, head_b = malloc(sizeof *head_b), b, t, temp, h;
	int i;
	//Init list
	for(i = 0; i < 100; i++){
		x = (x->next = malloc(sizeof *x));
		x->Item = rand() % 1000;
		printf("%d\t", x->Item);
	}
	printf("\n\n");
	x->next = NULL;
	b = head_b;
	b->next = NULL;
	//linked list sort
	for(t = head_a->next; t!= NULL; t = h){
		h = t->next;
		for(temp = b; temp->next != NULL; temp = temp->next){
			if(temp->next->Item > t->Item)
				break;
		}
		t->next = temp->next;
		temp->next = t;
	}
	//printf sort result
	temp = head_a->next;
	while(temp != NULL){
		printf("%d\t", temp->Item);
		temp = temp->next;
	}
	

}
