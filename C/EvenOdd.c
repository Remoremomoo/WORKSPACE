#include <stdio.h>

int main(){
	int a, b, c, d, e, totalMarks;
	float percentage;
	
	a = 75;
	b = 89;
	c = 67;
	d = 69;
	e = 100;
	
	totalMarks = a + b + c + d + e;
	percentage = (totalMarks / 500.0) * 100;
	
	printf("The Total marks of all 5 subjects is %d.\n", totalMarks);
	printf("The Percentage of all 5 subjects is %.2f%%.", percentage);
	
	return 0;
}
