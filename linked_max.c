/*
Write a recursive program that finds the maximum element in a linked list.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node *link;
struct node{
	int item;
	link next;
};

int Rand(){
	return rand() % 1000;

}

int maxnum = 0;
void max(link a){
	if(a == NULL)
		return;
	//printf("%d\t", a->item);
	if(maxnum < a->item){
		maxnum = a->item;
		//printf("%d\n", maxnum);
	}
	max(a->next);
}
int main(){
	int i, N = 50;
	link a = malloc(sizeof *a), t = a, temp = a;
	t->item = Rand();
	printf("%d\t", t->item);
	for(i = 0; i < N; i++){
		t = (t->next = malloc(sizeof *t));
		t->item = Rand();
		printf("%d\t", t->item);
	}
	printf("\n");
	max(temp);
	printf("%d\n", maxnum);

}
