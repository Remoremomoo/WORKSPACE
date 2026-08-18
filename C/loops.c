#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void ui(){
	printf("-----| LOOPS |-----\n\n");
}
void again(){
	printf("\nTry Again [Yes/No]?\n");	
}
void end(){
	printf("\nThank you for using LOOPS!");
	printf("\n\n\nLOOPS 2025\nAll rights reserved.");
}


int main(){
	int i, x;
	char choice[10];
	
	do{
		system("cls");
		ui();
		printf("Enter a number to print: ");
		scanf("%d", &x);
		
		for(i = 1; i <= x; ++i){
			printf("%d\n", i);
			sleep(1);
		}
		again();
		scanf(" %s", choice);
	}while(strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0);
	end();
	return 0;
}
