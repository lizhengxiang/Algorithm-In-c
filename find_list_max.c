/*write a functio that moves the largest item on
*a give list to be the final node on the list*/
#include<stdio.h>
#include<stdlib.h>
//define struct
typedef struct node* link;
struct node{
	int item;
	link next;
};

int main(){
	link x = malloc(sizeof *x), head_x = x, temp_1 = x, temp_2, temp_4, temp_3;
	int i, j = 0;
	// Init and find max node pioneer
	for(i = 0; i < 100; i++){
		x = (x->next = malloc(sizeof *x));
		x->item = rand() % 1000;
		if(j < x->item){
			j = x->item;
			temp_2 = temp_1;
		}
		temp_1 = x;
		printf("%d\t", x->item);
	}
	printf("\n\n");
	//save max node
	temp_3 = temp_2->next;
	//delete max node
	temp_2->next = temp_2->next->next;
	//insert max give final;
	x->next = temp_3;
	temp_3->next = NULL;
	//printf result
	temp_4 = head_x->next;
	while(temp_4 != NULL){
		printf("%d\t", temp_4->item);
		temp_4 = temp_4->next;
	}
	printf("\n");
	return 0;
}
