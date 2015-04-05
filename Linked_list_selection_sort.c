/*
Selection sort of a linked list is straightforward, but differs slightly from the array 
versionbecause it is easier to insert at the front of a list. We maintain an input list (pointed to by
h->next), and an output list (pointed to by out). While it is nonempty, we scan the input
list to find the maximum remaining element, then remove that element from the input list
and insert it at the front of the output list. This implementation uses an auxiliary routine
findmax, which returns a link to the node whose link points to the maximum element on a
list (see Exercise 3.34).
*/

#include<stdio.h>
#include<stdlib.h>
#define N 100

int Rand(){
	return rand() % 1000;
}
typedef struct Node *link;
struct Node{
	int item;
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
	int i, n = 0;
	for(i = 0; i < N; i++){
		x = (x->next = malloc(sizeof *x));
		x->item = Rand();
	}
	x->next = NULL;
	//head_b = head_a;
	head_b = listselection(head_a);
	printf("\n");
	while(head_b->next != NULL){
		printf("%d\t", head_b->item);
		head_b = head_b->next;
		if(++n % 10 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
	
}
