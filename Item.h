typedef int Item;
int eq(float a, float b){
	//printf("%0.2f\n", fabs(a-b));
	if(fabs(a-b) < 0.000001)
		return 1;
	else
		return 0;
}
