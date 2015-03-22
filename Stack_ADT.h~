typedef char Item;
//Init stack
//void STACKinit(int N){
//	Item stack[N];
//}
//stack pointer
int push = 0;
Item stack[10];
//judge stack empty
int STACKempty(){
	if(0 == push)
		return 0;
	else 
		return 1;
}

//stack push
void STACKpush(Item num){
	stack[push++] = num;
}
//stack pop
Item STACKpop(){
	return stack[push--];
}
