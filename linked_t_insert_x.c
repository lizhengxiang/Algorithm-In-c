//given pointers x and t to nides on circular list,write a code 
//fragment that moves the node following t to the poition following
//the node following x on the list
#include<stdio.h>
#include<stdlib.h>
#define N 100; 
typedef struct node* link;
struct node{
	link next;
	int Item;
};

int main(){
	int i;
	//circular link 1
	link m = malloc(sizeof *m), n = m, x, t;
	m->next = m;
	m->Item = 0;
	//circular link 2
	link o = malloc(sizeof *t), p = 0;
    o->next = o;
    o->Item = 0; 
	//initialize link 1 and 2
	for(i = 1; i < 100; i++){
		m = (m->next = malloc(sizeof*m));
		m->Item = i;
		if(i == 50)
			x = m;
		o = (m->next = malloc(sizeof*o));
        o->Item = i;
        	if(i == 60)
 		        t = o;
	}
	m->next = n;
	o->next = p;
	t->next = x->next;
	x->next = t;
	m = m->next;
	while(m->next != n){
		printf("%d\t", m->Item);
		m = m->next;
	}
	return 0;
}
