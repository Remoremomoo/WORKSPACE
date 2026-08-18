#include <stdio.h>

int main(){
	int a[10], i, sum = 0;
	
	printf("SUMMATION OF ARRAYS");
	for(i = 0; i < 10; i++){
		printf("\n\nEnter values for %d: ", i);
		scanf("%d", &a[i]);
	}
	for(i = 0; i < 10; i++){
		sum += a[i];
	}
	printf("The sum of 10 numbers is %d", sum);
	return 0;
}
