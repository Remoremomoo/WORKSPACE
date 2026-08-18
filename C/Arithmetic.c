#include <stdio.h>

int main(){
	int a, b, choice;
	double quo;
	
	printf("\n-----| CALCULATOR |-----\n");
	printf("\nOPERATORS\n");
	printf("\n1. Addition");
	printf("\n2. Subtraction");
	printf("\n3. Multiplication");
	printf("\n4. Division");
	printf("\n5. Remainder");
	printf("\n6. Exit\n");
	printf("\nChoose Operation: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("\nEnter your values: ");
			scanf("%d %d",&a, &b);
			
			printf("\nThe sum of %d and %d is %d.", a, b, a + b);
		
			break;
		
		case 2:
			printf("\nEnter your values: ");
			scanf("%d %d",&a, &b);
			
			printf("\nThe difference of %d and %d is %d.", a, b, a - b);
			
			break;
		
		case 3:
			printf("\nEnter your values: ");
			scanf("%d %d",&a, &b);
			
			printf("\nThe product of %d and %d is %d.", a, b, a * b);
			
			break;
		
		case 4:
			printf("\nEnter your values: ");
			scanf("%d %d",&a, &b);
			
			quo = (double)a / b;
			
			if(b != 0){
			printf("\nThe quotient of %d and %d is %lf", a, b, quo);
			}
			else{
				printf("\nERROR: DIVISION BY ZERO!");
			}
			
			break;
		
		case 5:
			printf("\nEnter your values: ");
			scanf("%d %d",&a, &b);
			printf("\nThe remainder of %d and %d is %d.", a, b, a % b);
			
			break;
		
		case 6:
			printf("\nCLOSING TERMINAL...");
			
			break;
		
		default:
			printf("\nINVALID CHOICE!");
			printf("\n\nCLOSING TERMINAL...");
			
			break;
	}
	
	
	
	
	
	return 0;
}
