#include <stdio.h>

int main(){
	int a, b, sum, diff, prod;
	float quo;
	char choice;
	
	printf("\n-----| TCALC |-----\n");
	printf("\n+-*/| OPERATIONS |\\*-+\n");
	printf("\n1. Addition (+)\n");
	printf("2. Subtraction (-)\n");
	printf("3. Multiplication (*)\n");
	printf("4. Division (/)\n");
	printf("5. Exit (E)");
	printf("\n\nEnter your operator/decision: ");
	scanf("%c",&choice);
	
	if(choice == '+'){
		printf("\n>>>>| VALUES |<<<<\n");
		printf("Enter your two numbers: ");
		scanf("%d %d",&a, &b);
		
		sum = a + b;
		
		printf("\nThe sum of %d and %d is %d.", a, b, sum);
		printf("\n\nCLOSING TERMINAL...");
	}
	else if(choice == '-'){
		printf("\n>>>>| VALUES |<<<<\n");
		printf("Enter your two numbers: ");
		scanf("%d %d",&a, &b);
		
		diff = a - b;
		
		printf("\nThe difference of %d and %d is %d.", a, b, diff);
		printf("\n\nCLOSING TERMINAL...");
	}
	else if(choice == '*'){
		printf("\n>>>>| VALUES |<<<<\n");
		printf("Enter your two numbers: ");
		scanf("%d %d",&a, &b);
		
		prod = a * b;
		
		printf("\nThe product of %d and %d is %d.", a, b, prod);
		printf("\n\nCLOSING TERMINAL...");
	}
	else if(choice == '/'){
		printf("\n>>>>| VALUES |<<<<\n");
		printf("Enter your two numbers: ");
		scanf("%d %d",&a, &b);
		
		quo = (float)a / b;
		
		if(b != 0){
			printf("\nThe quotient of %d and %d is %.2f", a, b, quo);
			printf("\n\nCLOSING TERMINAL...");
		}
		else{
			printf("\nERROR: INVALID DIVISION BY ZERO!!");
			printf("\n\nCLOSING TERMINAL...");
		}
	}
	else if(choice == 'E'){
		printf("\nThank you for using TCalc!");
		printf("\n\nCLOSING TERMINAL...");
	}
	else{
		printf("\n\nINVALID CHOICE!!");
		printf("\n\nCLOSING TERMINAL...");
	}
	
	return 0;
}
