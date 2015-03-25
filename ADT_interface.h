/*
*This interface is identical to the pushdown stack interface of Program 4.4, except for the
*names of the functions. The two ADTs differ only in the specification, which is not
*reflected in the interface code.
*/
#include<stdlib.h>
static int *id, *sz;
void UFinit(int N){
	int i;
	id = malloc(N * sizeof(int));
	sz = malloc(N * sizeof(int));
	for(i = 0; i < N; i++){
		id[i] = i;
		sz[i] = 1;
	}
}

static int find(int x){
	int i = x;
	while(i != id[i])
		i = id[i];
	return i;
}

int UFfind(int p, int q){
	return (find(p) == find(q));
}

void UFunion(int p, int q){
	int i = find(p), j = find(q);
	if(i == j)
		return ;
	if(sz[i] < sz[j]){
		id[i] = j;
		sz[j] += sz[i];
	}else{
		id[j] = i;
		sz[i] += sz[j];
	}
}

