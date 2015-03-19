/*Impelement a code fragment for a linked list that exchanges the positions
*of the nodes after the nodes referencend by two given links t and u
*/
#include<stdio.h>
#include<stdlib.h>
//define struct
typedef struct node* link;
struct node{
	int item;
	link next;
};

int main(){
	link a = malloc(sizeof *a), head_a = a, temp_1, temp_2, t, u, b;
	int i;
	//Init links and find t, u
	for(i = 0; i < 100; i++){
		a = (a->next = malloc(sizeof*a));
		a->item = i;
		if(i == 20){
			temp_1 = a;
		}
		if(i == 50){
			temp_2 = a;
		}
	}
	a->next = NULL;
	t = temp_1->next;
	u = temp_2->next;
	//delete t and u
	temp_1->next = temp_1->next->next;
	temp_2->next = temp_2->next->next;
	//insert t and u
	t->next = temp_2->next;
	temp_2->next = t;
	u->next = temp_1->next;
	temp_1->next = u;
	//printf links
	b = head_a->next;
	while(b->next != NULL){
		printf("%d\t", b->item);
		b = b->next;
	} 
	printf("\n");
	return 0;
}
