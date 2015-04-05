/*
Give the contents of the input list and output list as Program 6.16 is used for the keys
A S O R T I N G E X A M P L E.
*/

#include<stdio.h>
#include<stdlib.h>
#define N 15

typedef char Item;
int Rand(){
	return rand() % 1000;
}

typedef struct Node *link;
struct Node{
	Item item;
	link next;
};

link findmax(link h){
	int max = -1;
	link max_1, max_2;
	while(h->next != NULL){
		max_1 = h->next;  //find max node precursor
		if(max < max_1->item){
			max = max_1->item;
			max_2 = h;
		}
		h = h->next;
	}
	//printf("%d\t", ->item);
	return max_2;
}

link listselection(link h){
	link max, t, out = NULL;
	while(h->next != NULL){
		max = findmax(h);
		t = max->next; // save max node
		max->next = t->next;  //delete max node
		t->next = out; //input node
		out = t;
	}
	h->next = out;
	return h;
}

int main(){
	link head_a, head_b, x = malloc(sizeof(*x));
	head_a = x;
	Item a[N] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
	int i, n = 0;
	printf("former data: ");
	for(i = 0; i < N; i++)
		printf("%c  ", a[i]);
	printf("\n");
	for(i = 0; i < N; i++){
		x = (x->next = malloc(sizeof *x));
		x->item = a[i];
	}
	x->next = NULL;
	//head_b = head_a;
	head_b = listselection(head_a);
	printf("sort finish data: ");
	while(head_b->next != NULL){
		printf("%c  ", head_b->item);
		head_b = head_b->next;
		//if(++n % 10 == 0)
		//	printf("\n");
	}
	printf("\n");
	return 0;
	
}
