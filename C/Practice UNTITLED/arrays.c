#include <stdio.h>

int main(){
	int a[10], i;//so ung a[10], gagawa sia ng 10 containers starting from label 0-9. 
	
	for(i = 0; i < 10; i++){//itong loop na to is magiistart sya sa 0, representing yung label ng container.
	//since naka loop sya, titigil sya hanggang sa mkaabot sya sa container 9 since i < 10.
		printf("Enter value for container %d: ", i);
		scanf("%d", &a[i]);//itong scanf is magiinput ka ng value per container. since
		//mag iistart ung i sa 0, and &a[i] ung paglalagyan, bali kung ano ung value ng i, un ung 
		//container na paglalagyan.
	}
	printf("\n\nValues per container in reversed order:");
	for(i = 9; i >= 0; i--){
		//eto namang loop, bale magiistart muna sa 9 hanggang makaabot ng 0.
		printf("\n%d", a[i]);
	}//etong printf, ipiprint nia lahat ng value sa container starting from a[9] kse sa 9 magiistart
	//ung i dito.
	
	return 0;
}
