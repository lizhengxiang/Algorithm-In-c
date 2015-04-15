#include<stdio.h>
#include<stdlib.h>

typedef int Item;

#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b){Item t = a; a = b; b = t;}
#define compexch(a,b) if(less(a,b)) exch(a,b)

static int number = 0;

void shellsort(Item a[], int l, int r){
	int i, h, j = 0;
	int num[20];
	num[0] = 1;
	/*num[1] = 8;
	num[2] = 23;
	num[3] = 77;
	num[0]=1;*/
	if((r-1)/9>8){
		h = 8;
		j = 1;	
	}
	else{
		h = 1;
		j = 0;
	}
	num[1]=8;
	if((r-1)/9>8){
		h = 8;
		for(i = 1; h < (r-1)/9; i++){
			int x = 1, y = 1, z;
			for(z=0; z<=i; z++)
				x *= 4;
			for(z=0; z<i; z++)
				y *= 2;
			y *= 3;
			num[i+1] = x + y + 1;
			h = num[i+1];
			j = i+1;
			//printf("%d\n",j);
		}
	}
	//for(i = 0; i <= j; i++)
		//printf("#########%-5d", j);

	
	for(h = num[j]; j>=0; h = num[--j])
		for(i=l+h; i<=r; i++){
			int j = i, v = a[i];
			while(j>=l+h&&less(v,a[j-h])){
				a[j] = a[j-h];
				j -= h;
				++number;
			}
			a[j] = v;
		}
}

int main(){
	int i, N = 100;
	Item a[N];
	for(i = 0; i < N; i++)
		a[i] = rand()%10000;
	shellsort(a, 0, N-1);
	for(i = 0; i < N; i++){
		printf("%-8d", a[i]);
		if((i+1)%10 == 0)
			printf("\n");
	}
	printf("\n");
	printf("number = %d\n", number);
	return 0;
}
