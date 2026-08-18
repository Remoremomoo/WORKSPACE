#include <stdio.h>

int main(){
	int a, b;
	
	printf("\n-----| RELATIONAL |-----\n");
	printf("\nEnter your two numbers: ");
	scanf("%d %d",&a, &b);
	
	if(a > b){
		printf("\n%d is greater than %d.", a, b);
	}
	else if(a == b){
		printf("\n%d and %d are equal.", a, b);
	}
	else{
		printf("\n%d is less than %d.", a, b);
	}
	
	
	printf("\n\nCLOSING TERMINAL...");
	return 0;
}
