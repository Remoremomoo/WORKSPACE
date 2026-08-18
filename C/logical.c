#include <stdio.h>

int main(){
	int a;
	
	printf("\n-----| LOGICAL OPERATORS |-----\n");
	printf("\nEnter your number: ");
	scanf("%d",&a);
	
	if(a > 10 && a < 50){
		printf("\nThe value \"%d\" is in between 10 and 50.", a);
	}
	else{
		printf("\nThe value \"%d\" is not in between 10 and 50.", a);
	}
	printf("\n\nCLOSING TERMINAL...");
	return 0;
}
