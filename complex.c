#include<stdio.h>
#include<math.h>
#include"complex_ADT.h"
#define PI 3.14
int main(){
	int i, j, N = 10;
	Complex t, x;
	for(i = 0; i < N; i++){
		float r = 2.0 * PI * i / N;
		t = COMPLEXinit(cos(r), sin(r));
		printf("%2d\t%6.3f\t%6.3f\n", i, Re(t), Im(t));
		for(x = t, j = 0; j < N - 1; j++){
			x = COMPLEXmult(t, x);
			printf("%6.3f\t%6.3f\n", Re(x), Im(x));
		}
	}
	return 0;
}
