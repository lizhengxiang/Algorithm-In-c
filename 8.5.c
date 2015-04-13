/*
This program merges without using sentinels by copying the second array into aux in
reverse order back to back with the first (putting aux in bitonic order). The first for loop
moves the first array and leaves i pointing to l, ready to begin the merge. The second for
loop moves the second array, and leaves j pointing to r. Then, in the merge (the third for
loop), the largest element serves as the sentinel in whichever array it is. The inner loop of
this program is short (move to aux, compare, move back to a, increment i or j, increment
and test k).

Show how the keys AEQSUYEINOST are merged using Program 8.2, in the style of
the example diagrammed in Figure 8.1.
*/
#include<stdio.h>
#define N 12
typedef char Item;
void merge(Item *a, int l, int m, int r){
	Item aux[N];
	int i, j, k, temp;
	for(i = m; i >= l; i--)
		aux[i] = a[i];
	for(j = m; j < r; j++)
		aux[r+m-j] = a[j+1];
	i += 1;
	for(k = l; k < r; k++){
		for(temp = i; temp < j; temp++)
        	printf("%c ", aux[temp]);
        printf("\t\t");
		a[k] = (aux[j] < aux[i])?aux[j--]:aux[i++];
		for(temp = 0; temp < k; temp++)
			printf("%c ", a[temp]);
		printf("\n");
	}
}

int main(){
	int i, j, m;
	Item a[N] = {'A','E','Q','S','U','Y','E','I','N','O','S','T'};
	m = 5;
	merge(a, 0, m, N-1);
	for(i = 0; i < N; i++){
		//if(i % 10 == 0)
		//	printf("\n");	
		printf("%c\t", a[i]);
	}
	printf("\n");
	return 0;
}
