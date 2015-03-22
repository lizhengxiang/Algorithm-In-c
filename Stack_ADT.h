#include<stdlib.h>

typedef int Item;
Item *s;
int N;


void STACKinit(int a){
	s = malloc(a * sizeof(Item));
	N = 0;
}

int STACKempty(){
	return N==0;
}

void STACKpush(Item a){
	s[N++] = a;
}

Item STACKpop(){
	return s[--N];
}
