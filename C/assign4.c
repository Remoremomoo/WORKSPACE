#include <stdio.h>

int main(){
	int x, y;
	
	printf("\n-----| ASSIGN 4 |-----\n");
	
	printf("\nEnter the value of x: ");
	scanf("%d",&x);
	
	y = --x;
	
	printf("\n\nThe pre-decrement value of y is %d.", y);
	printf("\nThe value of x is %d.", x);
	
	printf("\n\nCLOSING TERMINAL...");
	return 0;
}
