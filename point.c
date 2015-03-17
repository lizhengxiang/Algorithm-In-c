#include<stdio.h>
#include<math.h>

typedef struct{
	float x;
	float y;
} point;

float distance(point a, point b){
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main(){
	point a, b;
	a.x = 2, b.x = 0;
	a.y = 0, b.y = 0;
	float dis = distance(a,b);
	printf("%0.2f\n",dis);
	return 0;
}
