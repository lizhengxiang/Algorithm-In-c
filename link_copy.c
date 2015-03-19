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
//define function copy a
link copy_link(link b){
	link m = malloc(sizeof*m), head_b = m;
	int i;
	while(b->next != NULL){
		m = (m->next = malloc(sizeof*m));
		m->item = b->next->item;
		b = b->next; 
	}
	m->next = NULL;
	return head_b;
	

}
int main(){
	link a = malloc(sizeof *a), head_a = a, head_b, t, temp_1;
	int i;
	//Init links and find t, u
	for(i = 0; i < 100; i++){
		a = (a->next = malloc(sizeof*a));
		a->item = i;
		//printf("%d\t", a->item);
	}
	a->next = NULL;
	head_b = copy_link(head_a);
	t = head_b->next;
	temp_1 = head_a->next;
	while(temp_1 != NULL){
		printf("%d\t", temp_1->item);
		temp_1 = temp_1->next;
	}
	printf("\n\n");
	while(t != NULL){
		printf("%d\t", t->item);
		t = t->next;
	}
	printf("\n");
	return 0;
}
