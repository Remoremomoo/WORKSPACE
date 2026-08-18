#include <stdio.h>

int main(){
	int a[10], i, largest, smallest;
	
	printf("LARGEST AND SMALLEST ARRAY");
	
	for(i = 0; i < 10; i++){
		printf("\n\nEnter value for container %d: ", i);
		scanf("%d", &a[i]);
	}
	largest = a[0];
	smallest = a[0];
	for(i = 1; i < 10; i++){
		if(a[i] > largest){
		
			largest = a[i];
		}
		if(a[i] < smallest){
		
			smallest = a[i];
		}
	}
	printf("\n\nThe largest number is %d", largest);
	printf("\nThe smallest number is %d", smallest);
	return 0;
}
