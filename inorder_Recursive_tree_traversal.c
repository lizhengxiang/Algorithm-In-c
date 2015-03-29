#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node* link;
struct node{
	char data;
	link lchild, rchild;
};
void createBitree(link &T){	
	char ch;
	ch = getchar();
	if(ch == ' ')
		T = NULL;
	else{
		T = (link)malloc(sizeof (node));  
		T->data = ch;
		createBitree(T->lchild); //createBitree - lchild
		createBitree(T->rchild); //createBitree - rchild
	}
	return ;
}
//inorder Recursive tree traversal
void preorder(link Tree){
	if(Tree == NULL)
		return;
	preorder(Tree->lchild);
	printf("%c", Tree->data);
	preorder(Tree->rchild);
}

int main(){
	int i = 0;
	link Tree;
	createBitree(Tree);
	preorder(Tree);
	printf("\n");
	return 0;
}
