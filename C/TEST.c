#include <stdio.h>

int main(){
	int A, B, C, D, Largest;
	
	A = 1;
	B = 2;
	C = 3;
	D = 2;
	
	Largest = A;
	
	if(B > Largest){
		Largest = B;
	}
	if(C > Largest){
		Largest = C;
	}
	if(D > Largest){
		Largest = C;
	}
	
	printf("The largest variable is %d.", Largest);
	
	return 0;
	
}
