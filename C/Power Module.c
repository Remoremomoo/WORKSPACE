#include <stdio.h>
#include <stdlib.h>

int main(){
	int option;
	
	do{
		printf("\n|-----POWER MODULE-----\n");
		printf("\nOPTIONS\n");
		printf("1. Shutdown\n");
		printf("2. Restart\n");
		printf("3. Exit Terminal\n");
		printf("\nChoose your option: ");
		scanf("%d",&option);
		
		switch(option){
			case 1:
				printf("\nShutting down your PC...\n");
				system("shutdown /s /t 0");
				break;
				
			case 2:
				printf("\nRestarting your PC...\n");
				system("restart /r /t 0");
				break;
				
			case 3:
				printf("\nClosing Terminal...\n");
				break;
				
			default:
				printf("\nINVALID CHOICE!\n");
				break;
				
		}
	}
	while(option != 3);
	
return 0;
}
