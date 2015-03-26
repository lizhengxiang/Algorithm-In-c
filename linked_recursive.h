/*
The first function, count, counts the number of nodes on the list. The second,
traverse, calls the function visit for each node on the list, from beginning to end.
These two functions are both also easy to implement with a for or while loop. The third
function, traverseR, does not have a simple iterative counterpart. It calls the function
visit for every node on the list, but in reverse order.
The fourth function, remove, removes all the nodes having a given item value from a list.
The key to the implementation is the link change x = x->next in the predecessor of
each node to be deleted, which is made possible by the use of a reference parameter. The
structural changes for each iteration of the while loop are the same as diagrammed in
Figure 3.3, but x and t here both refer to the same node.
*/

int count(link x){
	if( x == NULL)
		return 0;
	return 1 + count(x->next);
}

void traverse(link h, void(*visit)(link)){
	if( h == NULL)
		return ;
	(*visit)(h);
	traverse(h->next, visit);
}

void traverseR(link h, void (*visit)(link)){
	if(h == NULL)
		return ;
	traverseR(h->next, visit)
	(*visit)(h);
}

link Delete(link x, Item v){
	if(x == NULL)
		return NULL;
	if(eq(x->item), v){
		link t = x->next;
		free(x);
		return t;
	}
	x->next = Delete(x->next, v)
	return x;
}
