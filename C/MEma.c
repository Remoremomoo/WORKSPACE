#include <stdio.h>

int main(){
	int a = 10, b = 5, c1, c2, c3, c4;
	
	c1 = a;
	c2 = a += b;
	c3 = a -= b;
	c4 = a *= b;
	
	printf("The sum of a and b is %d\n", c3);
	
	if(a == b){
		printf("a is equal to b\n");
		printf("a is greater than b");
	}
	else if(a > b){
		printf("a is greater than b");
	}
	else{
		printf("a is not equal to b\n");
		printf("a is less than b");
	}
	return 0;
}
