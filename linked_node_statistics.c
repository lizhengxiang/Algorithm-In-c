#include<stdio.h>
#include<stdlib.h>
typedef struct node* link;
struct node{
	//int Item;
	link next;
};

int main(){
	int i, j = 0;
	link t = malloc(sizeof *t), x = t, m, n;
	//t->Item;
	t->next = t;
	for(i = 0; i < 100; i++){
		x = (x->next = malloc(sizeof *t));
		if(i == 50)
			m = x;
		if(i == 22)
			n = x;
	}
	x->next = t;
	while(m->next != n){
		++j;
		m = m->next; 
	} 
	printf("%d\n", j);
	return 0;
}
