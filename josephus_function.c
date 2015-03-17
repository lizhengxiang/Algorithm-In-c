#include<stdio.h>
#include<stdlib.h>

typedef struct node* link;
struct node{
	int Item;
	link next;
};

int main(){
	int i, N = 9, M = 5;
	link t = malloc(sizeof *t), x = t, temp;
	t->next = t;
	t->Item = 1;
	for(i = 2; i < 10; i++){
		x = (x->next = malloc(sizeof *x));
		x->Item = i;
		//x->next = t;
	}
	x->next = t;
	while(x != x->next){
		for(i = 1; i < M; i++)
			x = x->next;
			temp = x->next;
			x->next = x->next->next;
			N--;
			free(temp);
	}
	printf("%d\t%d\n", N, x->Item);
	return 0;

}
