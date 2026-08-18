#include <stdio.h>

int main(){
	int a, b, sum, diff, prod;
	float quo;
	
	
	printf("\nWELCOME TO BASIC CALCULATOR\n");
	printf("\nEnter your first number: ");
	scanf("%d",&a);
	printf("\nEnter your second number: ");
	scanf("%d",&b);
	
	sum = a+b;
	diff = a-b;
	prod = a*b;
	quo = (float)a/b;
	
	printf("\nThe sum of %d and %d is %d.\n", a, b, sum);
	printf("The difference of %d and %d is %d.\n", a, b, diff);
	printf("The product of %d and %d is %d.\n", a, b, prod);
	printf("The quotient of %d and %d is %.2f.", a, b, quo);
	
	return 0;
}
