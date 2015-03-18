/*write a function that rearranges a linked list to put the node
* in even positions after the nodes in old positions in the lit.
* preserving the relative order of both the even and the odds.
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
	link a = malloc(sizeof(*a)), head_a = a, 
		 b = malloc(sizeof(*b)), head_b = b, b1 = b,
		 c = malloc(sizeof(*b)), head_c = c, c1 = c,
		 d = malloc(sizeof(*d)), head_d = d, temp = a;
	int i;
	for(i = 0; i < 100; i++){
		a = (a->next = malloc(sizeof*a));
		a->item = i; 
		printf("%d\t", i);
	}  
	printf("\n\n");
	a->next = NULL;
	for(i = 0; i < 100; i++){
		if(i % 2 == 0){
			b = temp->next;
			b = b->next;
		}
		else{
			c = temp->next;
			c = c->next;
		}
		temp = temp->next;
	}
	//printf("aaaaaaaaaa");
	b->next = NULL;
	//c->next = NULL;
	/*for(i = 0; i < 99; i++){
		if(i % 2 == 0){ 
			d->next = c1->next;
			c1 = c1->next;
		}
		else{
			d->next = b1->next;
			b1 = b1->next;
		}
		d = d->next;
	}*/
	while(head_c != NULL){
		printf("%d\t", head_c->item);
		head_c = head_c->next;
	}
	printf("\n");
	return 0;
}
