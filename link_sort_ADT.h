/*
This interface for linked lists can be contrasted with the one for arrays in Program 6.7. The
randlist function builds a list of random items, including storage allocation. The
showlist function prints out the keys in the list. Sorting programs use overloaded
operator< to compare items and manipulate pointers to rearrange the items. The data
representation for nodes is specified in the usual way (see Chapter 3), and includes a
constructor for nodes that fills in each new node with the given value and a null link.
struct node

	typedef node *link;
	link randlist(int);
	link scanlist(int&);
	void showlist(link);
	link sortlist(link);
*/

#include<stdio.h>
#include<stdlib.h>
typedef char Item;

typedef struct Node *link;
struct Node{
	Item item;
	link next;
};
link head_a;
link NEW(Item item, link next){
	link x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	return x;
}

link init(int a){
	head_a = NULL;
}

void show(link a){
	while(a->next != NULL){
		printf("%c\t", a->item);
		a = a->next;
	}
}

link sort(link h){
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
	return max_2;
}

