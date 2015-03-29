#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node* link;
struct node{
	char data;
	link lchild, rchild;
};
int i = 0;
link tree;
void createBitree(link &T){	
	char ch;
	ch = getchar();
	if(ch == ' ')
		T = NULL;
	else{
		//printf("****");
		T = (link)malloc(sizeof (node));
		if(i == 0){
			tree = T;
    	    i++;
 
 	    }   
		T->data = ch;
		createBitree(T->lchild); //createBitree - lchild
		createBitree(T->rchild); //createBitree - rchild
	}
	//preorder(tree);
	return ;
}
//postorder Recursive tree traversal
void preorder(link Tree){
	//printf("JJJJJJJ");
	if(Tree == NULL)
		return;
	preorder(Tree->lchild);
	preorder(Tree->rchild);
	printf("%c", Tree->data);
}

int main(){
	int i = 0;
	link Tree;
	createBitree(Tree);
	preorder(Tree);
	printf("\n");
	return 0;
}
