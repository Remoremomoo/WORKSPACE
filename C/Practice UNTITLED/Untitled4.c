#include <stdio.h>

int main()
{
	
	int a, b, sum, diff, prod, quo;
	char name[20];
	
	printf("Enter your name: ");
	scanf("%s", name);
	printf("Enter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);
	
	sum = a+b;
	diff = a-b;
	prod = a*b;
	quo = a/b;
	
	printf("\nHello, %s!\n", name);
	printf("The sum is %d.\n", sum);
	printf("The difference is %d.\n", diff);
	printf("The product is %d.\n", prod);
	printf("The quotient is %d.\n", quo);
	
	
	return 0;
}
