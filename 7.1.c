#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define exch(a,b) {int t=a; a=b; b=t;}
#define key(a) (a)
#define less(a,b) (key(a)<key(b))

static int x = 0;
int randN(){
	return rand()%1000;
}

int partition(int a[], int l, int r){
	int i=l-1, j=r;
	int v=a[r];
	while(1){
		while(less(a[++i], v))
			++x;
		while(less(v,a[--j])){
			if(i==j)
				break;
			++x;
		}
		if(i>=j){
			j=i-l;
			break;
		}
		//if(a[i]==11111||a[j]==11111)
			++x;
		exch(a[i],a[j]);
	}
	exch(a[i],a[r]);
	return i;
}
void qusort(int a[], int l, int r){
	int i;
	if(r -l <= 0)
		return ;
	i = partition(a, l, r);
	qusort(a, l, i-1);
	qusort(a, i+1, r);
}
int main(){
	srand((int)time(0));
	time_t begin = clock();
	int N=10000;
	int a[N], i;
	//a[0]=11111;
	for( i=0; i<N; i++){
		a[i]=randN();
		//scanf("%d", &a[i]);
	}
	//a[400] = 11111;
	qusort(a, 0, N-1);
	for(i=0; i<N; i++){
		printf("%4d",a[i]);
		if((i+1)%10==0)
			printf("\n");
	}
	printf("\nnum=%d\n",x);
	printf("time = %ldms\n", (long int) 1000*(clock()-begin)/CLOCKS_PER_SEC);
	return 0;
}
