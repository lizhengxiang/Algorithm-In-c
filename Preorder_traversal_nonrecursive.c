/*
This nonrecursive stack-based function is functionally equivalent to its recursive
counterpart, Program 5.14
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char Item;
//#include"Stack_link_ADT.h"

typedef struct node* Link;
struct node{
	char data;
	Link lchild, rchild;
};
#include"Stack_ADT.h"

void createBitree(Link &T){	
	char ch;
	ch = getchar();
	if(ch == ' ')
		T = NULL;
	else{
		T = (Link)malloc(sizeof (node));  
		T->data = ch;
		createBitree(T->lchild); //createBitree - lchild
		createBitree(T->rchild); //createBitree - rchild
	}
	return ;
}
//inorder Recursive tree traversal
void preorder(Link Tree){
	char ch;
	
	STACKinit(20);

	STACKpush(Tree->data);
	while(STACKempty()){
		//printf("nn");
		ch = STACKpop();
		printf("%c", ch);
		if(Tree->rchild != NULL){
			Tree = Tree->rchild;
			STACKpush(Tree->data);
		}
		if(Tree->lchild!= NULL){
			Tree = Tree->lchild;
			STACKpush(Tree->data);
		}
	}
}

int main(){
	int i = 0;
	Link Tree;
	createBitree(Tree);
	preorder(Tree);
	printf("\n");
	return 0;
}
