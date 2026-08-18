// Program by Godfrey Inigo S. Sta. Ana
#include <stdio.h>

int main()
{
	int a, b, sum, diff, prod, quo;
	
	printf("Enter your desired value for A: ");
	scanf("%d",&a);
	printf("Enter your desired value for B: ");
	scanf("%d",&b);
	
	sum = a+b;
	diff = a-b;
	prod = a*b;
	quo = a/b;
	
	
	
	printf("The sum of %d and %d is %d.\n", a, b, sum);
	printf("The difference of %d and %d is %d.\n", a, b, diff);
	printf("The product of %d and %d is %d.\n", a, b, prod);
	printf("The quotient of %d and %d is %d.\n", a, b, quo);
	
	if(sum %2 == 0)
		printf("The sum is an even number");
	else
		printf("The sum is an odd number");
	
	return 0;
}
