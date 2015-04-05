/*
Give the contents of the input list and output list as Program 6.16 is used for the keys
A S O R T I N G E X A M P L E.

Implement a performance-driver client program for linked-list sorts (see Exercise 6.9).
*/

#include<stdio.h>
#include<stdlib.h>
#define N 15
typedef char Item;
typedef struct Node *link;
struct Node{
	Item item;
	link next;
};


link listselection(link h){
	//link a = h;
	int i;
	link temp_1, temp_2, temp;
	for(i = 0; i < N; i++){
		link a = h;
		while(a->next != NULL){
			temp = a;
			temp_1 = a->next;
			if(a->next != NULL){
				a = a->next;
				temp_2 = a->next;
			}
			else
				break;
			if(temp_1->item > temp_2->item){
				temp->next = temp_1->next;
				temp_1->next = temp_2->next;
				temp_2->next = temp_1;
				a = temp_1; 
			}
			else a = temp_2;
			printf("KKKKK");
		}
		printf("JJJ");
	}
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
	}
	printf("\n");
	return 0;
	
}
