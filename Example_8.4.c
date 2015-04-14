#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef int Item;
Item aux[N];

int Rand(){
	return rand() % 1000;
}

int less(int a, int b){
	if(a > b)
		return 0;
	else
		return 1;
}

void insertion(Item *a, int l, int r){
	int i;
	for(i = r-1; i > l; i--){
		if(a[i-1] > a[i]){
			int temp = a[i];
			a[i] = a[i-1];
			a[i-1] = temp;
		}
	}
	for(i = l+2; i < r; i++){
		int j = i;
		int v = a[i];
		while(less(v, a[j-1])){
			a[j] = a[j-1];
			j--;
		}
		a[j] = v;
	}
}

void mergeAB(Item *a, int l, int m, int r){
	Item aux[N];
	int i, j, k;
	for(i = m; i >= l; i--)
		aux[i] = a[i];
	for(j = m; j < r; j++)
		aux[r+m-j] = a[j+1];
	++i;
	for(k = l; k < r; k++)
		a[k] = (aux[j] < aux[i])?aux[j--]:aux[i++];
}


void mergesortABr(Item a[], int l, int r){
	int m = (l+r)/2;
	if(r-l <= 10){
		insertion(a, l, r);
		return ;
	}
	mergesortABr(a,  l, m);
	mergesortABr(a,  m+1, r);
	mergeAB(&a[l], l, m, r);
}

void mergesortAB(Item a[], int l, int r){
	int i;
	for(i = l; i <= r; i++)
		aux[i] = a[i];
	mergesortABr(a, l, r);
}

int main(){
	Item a[N];
	int i, j;
	for(i = 0; i < N/2; i++)
		a[i] = i;
	for(j = 0; i < N; i++)
		a[i] = j++;
	mergesortAB(a, 0, N-1);
	for(i = 0; i < N; i++){
		if(i % 10 == 0)
			printf("\n");
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
