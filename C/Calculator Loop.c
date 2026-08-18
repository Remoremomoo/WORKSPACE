#include <stdio.h>

int main()
{
	int a, b, sum, diff, prod;
	float quo;
	int option;
	
	do{
		printf("\n--- CALCULATOR ---\n");
		printf("\nOPERATIONS:\n");
		printf("\n1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Exit\n");
		printf("\nChoose your option: \n");
		scanf("%d",&option);
		
		if(option >= 1 &&  option <= 4){
		printf("\nEnter your first number: \n");
		scanf("%d",&a);
		printf("\nEnter your second number: \n");
		scanf("%d",&b);
		}
		
		sum = a+b;
		diff = a-b;
		prod = a*b;
		quo = (float)a/b;
		
		switch(option){
			case 1:
				printf("\nThe sum of %d and %d is %d.\n", a, b, sum);
				break;
			
			case 2:
				printf("\nThe difference of %d and %d is %d.\n", a, b, diff);
				break;
				
			case 3:
				printf("\nThe product of %d and %d is %d.\n", a, b, prod);
				break;
				
			case 4:
				if(b != 0){
				printf("The quotient of %d and %d is %.2f.\n", a, b, quo);
				}
				else{
					printf("\nERROR! DIVISION BY ZERO IS NOT ALLOWED!\n");
				}
				break;
				
			case 5:
				printf("\nExiting Calculator...");
				break;
				
			default:
				printf("\nINVALID CHOICE! Try Again.");
		}
			
	}
	while(option != 5);

return 0;	
}
