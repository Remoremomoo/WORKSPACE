#include <stdio.h>

int main(){
	int x;
	
	printf("\n-----| ASSIGN 1 |-----\n");
	
	printf("\nEnter the value of x: ");
	scanf("%d",&x);
	
	x += 5;
	
	printf("\n\nThe new value of x is %d.", x);
	
	printf("\n\nCLOSING TERMINAL...");
	return 0;
}
