#include <stdio.h>
#include <stdlib.h>

int main()
{
	int choice;
	
	printf("Choose an application to open:\n");
	printf("1. Calculator\n");
	printf("2. Notepad\n");
	printf("3. Paint\n");
	printf("\nEnter your choice [1, 2, 3]: ");
	scanf("%d",&choice);
	
	if(choice == 1){
		system("calc");
	}
	else if(choice == 2){
		system("notepad");
	}
	else if(choice == 3){
		system("mspaint");
	}
	else{
		printf("\nInvalid Number!\n");
		printf("\nTERMINAL CLOSING");
	}
	
	return 0;
}
