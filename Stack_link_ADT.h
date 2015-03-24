#include<stdlib.h>
typedef int Item;
typedef struct STACKnode* link;
struct STACKnode{
	Item item;
	link next;
};

static link head;
link NEW(Item item, link next){
	link x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	return x;
}

void STACKinit(int maxN){
	head = NULL;
}

int STATICempty(){
	return head == NULL;
}

STACKpush(Item item){
	head = NEW(item, head);
}

Item STACKpop(){
	Item item = head->next;
	link t = head->next;
	free(head);
	head = t;
	return item;
}
