#include<stdlib.h>
typedef char Item;

static Link head;
/*Link NEW(Link next){
	//link x =(link)malloc(sizeof *x);
	//x->item = item;
	x->lchild = next;
	return x;
}*/

void STACKinit(int maxN){
	head = NULL;
}

int STACKempty(){
	return head == NULL;
}

void STACKpush(Link Tree){
	Link temp = (Link) malloc(sizeof temp);
	temp = Tree;
	 = ;
	head = temp;
	printf("%c\n", temp->data);
}

Item STACKpop(){
	Item data = head->data;
	Link t = head->lchild;
	Item temp = head->data;
	free(head);
	head = t;
	return temp;
}
