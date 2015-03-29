#include<stdio.h>
#include<stdlib.h>
typedef struct node* link;

struct node{
	link lchild, rchild;
	char data;
};
// create Tree
int createtree(link T){
	char ch;
	ch = getchar();
	if(ch == ' ')
		T = NULL;
	else{
		T = malloc(sizeof *T);
		T->data = ch;
		createtree(T->lchild); //CreateBiTree - lchild
		createtree(T->rchild); //CreatebiTree - rchild
	}
	return 1;
}

int main(){
	link Tree;
	int i;
	i = createtree(Tree);
	if(i)
		printf("createtree succeed\n");
	else
		printf("createtree not secceed\n");

	return 0;
}
