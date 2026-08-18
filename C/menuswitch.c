#include <stdio.h>

int main(){
	int a, b;
	char option;
	printf("-----| MENU SWITCH |-----");
	printf("\n[+] Addition\n[-] Subtraction\n[*] Multiplication\n[/] Division\n[%%] Remainder");
	printf("\n\nChoose [+,-, *, /, %%]: ");
	scanf(" %c", &option);
	
	printf("\nEnter two values: ");
	scanf("%d %d", &a, &b);
	
	switch(option){
		case '+':
			printf("\nThe sum of %d and %d is %d.", a, b, a + b);
			break;
		case '-':
			printf("\nThe difference of %d and %d is %d.", a, b, a - b);
			break;
		case '*':
			printf("\nThe product of %d and %d is %d.", a, b, a * b);
			break;
		case '/':
			printf("\nThe quotient of %d and %d is %.2f.", a, b, (float)a / b);
			break;
		case '%':
			printf("\nThe remainder of %d and %d is %d.", a, b, a % b);
			break;
		default:
			printf("\nINVALID OPTION!");
			break;
	}
	return 0;
	
}
