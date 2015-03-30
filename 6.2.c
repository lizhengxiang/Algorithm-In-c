#include<stdio.h>
#include<stdlib.h>
#define N 11

int Rand(){
	return (rand()) % 4;
}
typedef struct Node node;
struct Node{
	int Num;
	int colour;
};

void sort(int *a, int l, int k){
	int i;
	for(i = l + 1; i <= k; i++){
		int j;
		for(j = i; j > i; j--)
			if(a[j-1] > a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
	}
}

int main(){
	node a[N];
	int b[N];
	int i, n, j;
	for(i = 1; i < N; i++){
		a[i].Num = i;
		printf("%d\t",a[i].colour = Rand());
	}
	printf("\n");
	for(i = 0; i < 4; i++){
		int tag = 1;
		n = 0;
				//printf("****");
		int k;
		//printf("**\n");
		for(k = 1; k < N; k++){
			if(i == a[k].colour){
				b[n++] = a[k].Num;
				tag = 0;
				//printf("%d\t", b[n-1]);

			}
		}
		//printf("\n");
		if(tag == 0){
			sort(b, 0, n -1);
			printf("colour %d:\t", i);
			for(j = 0; j < n; j++){
				printf("%d\t", b[j]);
			}	
			printf("\n");
		}
	}
}
