#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *fplog;
	char fullname[50];
	char file[] = "log.txt";
	int age, choice;
	char occ[20];
	
	fplog = fopen("log.txt", "a");
	if(fplog == NULL){
		printf("\n\n%s file does not exist!!", file);
		return 1;
	} 
	do{
	system("cls");
	printf("\t-----| LOG |-----");
	printf("\n\nEnter your full name (SURNAME, FIRST NAME MI.): ");
	scanf(" %[^\n]", fullname);
	printf("\nEnter your age: ");
	scanf("%d", &age);
	printf("\nEnter your occupation: ");
	scanf(" %s", occ);
	
	fprintf(fplog, "Name: %s | Age: %d | Occupation: %s\n", fullname, age, occ);
	printf("\n\nSUCCESFUL LOG! (Saved to log.txt)");
	printf("\n\nDo you want to log again?");
	printf("\n1. Yes\n2. No\nChoose: ");
	scanf("%d", &choice);
	
	}while(choice != 2);
	printf("\n\nThank you for logging!");
	fclose(fplog);
	return 0;
}
