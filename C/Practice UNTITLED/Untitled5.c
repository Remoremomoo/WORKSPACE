#include <stdio.h>
#include <string.h>

int main()
{
	char name[20];
	char correctName[] = "Godfrey";
	int a, b, sum, diff, prod;
	float quo;
	
	printf("Enter your name: ");
	scanf("%s",name);
	
	if(strcmp(name, correctName) != 0)
	{
		printf("\nWrong Name!\n");
		printf("Access Denied!\n");
		return 0;
	}
	
	printf("\nAccess granted. Hello, %s!\n", name);
	
	printf("Enter your first number: ");
	scanf("%d",&a);
	printf("Enter your second number: ");
	scanf("%d",&b);
	
	sum = a+b;
	diff = a-b;
	prod = a*b;
	quo = (float)a/b;
	
	printf("\nThe sum is %d.\n", sum);
	printf("The difference is %d.\n", diff);
	printf("The product is %d.\n", prod);
	printf("The quotient is %.2f.\n", quo);
	
	
	
	return 0;
}
