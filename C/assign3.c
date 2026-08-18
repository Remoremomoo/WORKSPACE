#include <stdio.h>

int main(){
	int x, y;
	
	printf("\n-----| ASSIGN 3 |-----\n");
	
	printf("\nEnter the value of x: ");
	scanf("%d",&x);
	
	y = ++x;
	
	printf("\n\nThe pre-increment value of y is %d.", y);
	printf("\nThe value of x is %d.", x);

	
	printf("\n\nCLOSING TERMINAL...");
	return 0;
}
