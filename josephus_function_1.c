/*implement a version of progriam 3.10 that uses a head node*/

#include<stdio.h>
#include<stdlib.h>
//define struct node
typedef struct node* link;
struct node{
	int Item;
	link next;
};

int main(){
	int i, N = 9, M = 5;
	link head_t = malloc(sizeof *head_t), t = head_t, x = head_t, temp;
	head_t->next = head_t;
	//Init link
	for(i = 1; i < 10; i++){
		x =(x->next = malloc(sizeof *x));
		x->Item = i;
	}
	x->next = head_t;
	t = head_t;
	//link dispose
	while(t != t->next && t->next != head_t){
		for(i = 1; i < M; i++){
			t = t->next;
			if(t->next == head_t)
			//jump head node
				t = t->next;
		}
		//delete node
		temp = t->next;
		t->next = t->next->next;
		free(temp);
	}
	printf("%d\n", t->Item);
	return 0;

}
