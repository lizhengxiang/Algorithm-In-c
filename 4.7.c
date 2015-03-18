#include<stdio.h>
#include<stdlib.h>

static int *id, *sz;
void UFinit(int N){
	int i;
	id = malloc(N*sizeof(int));
	sz = malloc(N*sizeof(int));
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
	return (find(p)==find(q));
}

void UFunion(int p, int q){
	int i = find(p);
	int j = find(q);
	if(i == j)
		return;
	if(sz[i] < sz[j]){
		id[i] = j;
		sz[j] += sz[i];
	}
	else{
		id[j] = i;
		sz[i] += sz[j];
	}
} 

int main(){
	int p, q;
	int N = 5;
	UFinit(N);
	while(scanf("%d %d", &p, &q) == 2){
		if(!UFfind(p,q)){
			UFunion(p,q);
			printf("%d   %d\n", p, q);
		}
	}
	return 0;
}
