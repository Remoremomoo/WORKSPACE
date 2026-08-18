#include <stdio.h>
#include <string.h>

int main()
{
	int pin, correctPin = 1112, a, b, sum, diff, prod;
	float quo;
	char password[20];
	char correctPassword[] = "Godfrey";
	char choice[10];
	char operation;
	
	
	printf("Enter your password: ");
	scanf("%s",password);
	
	if(strcmp(password, correctPassword) != 0){
		printf("\nWRONG PASSWORD!\n");
		printf("\nACCESS DENIED\n");
		printf("\nCLOSING TERMINAL");
		
		return 0;
	}
	
	printf("\nEnter your secondary PIN: ");
	scanf("%d",&pin);
	
	if(pin != correctPin){
		printf("\nINVALID PIN\n");
		printf("\nACCESS DENIED\n");
		printf("\nCLOSING TERMINAL\n");
		
		return 0;
	}
	
	printf("\nACCESS GRANTED\n\nWelcome, %s!", password);
	printf("\nDo you want to access calculator? (Yes/No): ");
	scanf(" %s",choice);
	
	if(strcmp(choice, "Yes") == 0){
		printf("\nEnter your first number: ");
		scanf("%d",&a);
		printf("Enter your second number: ");
		scanf("%d",&b);
		
		
		printf("\nChoose operation (+, -, *, /): ");
		scanf(" %c", &operation);
		
		sum = a+b;
		diff = a-b;
		prod = a*b;
		quo = (float)a/b;
		
		
		if(operation == '+'){
			printf("\nThe sum of %d and %d is %d.\n", a, b, sum);
			
			printf("\nThank you for using Calculator!");
			
			return 0;
		}
		
		else if(operation == '-'){
			printf("\nThe difference of %d and %d is %d.\n", a, b, diff);
			
			printf("\nThank you for using Calculator!");
			
			return 0;
		}
		
		else if(operation == '*'){
			printf("\nThe product of %d and %d is %d.\n", a, b, prod);
			
			printf("\nThank you for using Calculator!");
			
			return 0;
		}
		
		else if(operation == '/'){
			printf("\nThe quotient of %d and %d is %.2f\n", a, b, quo);
			
			printf("\nThank you for using Calculator!");
			
			return 0;
		}
		
		else{
			printf("\nINVALID OPERATION\n");
			printf("\nCLOSING TERMINAL");
		}
	}
	
	if(strcmp(choice, "No") == 0){
		printf("\nACTION TERMINATED\n");
		
		printf("\nCLOSING TERMINAL");
		
		return 0;
	}
	
	return 0;
	
}
