/*write a functio that moves the smallest item on
*a give list to be the first node on the list*/
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
	int i, j = 1200;
	// Init and find max node pioneer
	for(i = 0; i < 100; i++){
		x = (x->next = malloc(sizeof *x));
		x->item = rand() % 1000;
		if(j > x->item){
			j = x->item;
			temp_2 = temp_1;
		}
		temp_1 = x;
		printf("%d\t", x->item);
	}
	x->next = NULL;
	printf("\n\n");
	//save min node
	temp_3 = temp_2->next;
	//delete min node
	temp_2->next = temp_2->next->next;
	//insert min give first;
	temp_3->next = head_x->next;
	head_x->next = temp_3;
	//printf result
	temp_4 = head_x->next;
	while(temp_4 != NULL){
		printf("%d\t", temp_4->item);
		temp_4 = temp_4->next;
	}
	printf("\n");
	return 0;
}
