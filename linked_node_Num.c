#include<stdio.h>
#include<stdlib.h>
typedef struct node* link;
struct node{
	link next;
};

int main(){
	int i, j = 0;
	link t = malloc(sizeof *t), x = t, m;
	t->next = t;
	for(i = 0; i < 100; i++){
		x = (x->next = malloc(sizeof *t));
	}
	x->next = t;
	m = t->next;
	while(m != t){
		++j;
		m = m->next; 
	} 
	printf("%d\n", j);
	return 0;
}
