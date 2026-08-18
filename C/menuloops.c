#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ui1(){
	printf("-----| MENU LOOP |-----");
}
void ui2(){
	printf("\n1. Ascending\n2. Descending\n3. Odd Numbers\n4. Even Numbers\n5. Exit");
	printf("\n\nChoose an option: ");
}
void input(){
	printf("\n\nInput a number from 1-50: ");
}
void end(){
	printf("\nThank you for using MENULOOPS!");
	printf("\n\n\nMENULOOPS 2025\nAll rights reserved.");
}
int odd(int n){
	return n % 2 != 0;
}
int even(int n){
	return n % 2 == 0;
}

int main(){
	int choice, num, i;
	char again[10];
	
	do{
		system("cls");
		ui1();
		ui2();
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				system("cls");
				ui1();
				input();
				scanf("%d", &num);
				if(num >= 1 && num <= 50){
					printf("\nAscending order from 1 - %d:\n", num);
					for(i = 1; i <= num; ++i){
						printf("%d\n", i);
					}
				}
				else{
					printf("\n\nINVALID NUMBER!");
				}
				break;
			case 2:
				system("cls");
				ui1();
				input();
				scanf("%d", &num);
				if(num >= 1 && num <= 50){
					printf("\nDescending order from 1 - %d:\n", num);
					for(i = num; i >= 1; --i){
						printf("%d\n", i);
					}
				}
				else{
					printf("\n\nINVALID NUMBER!");
				}
				break;
			case 3:
				system("cls");
				ui1();
				input();
				scanf("%d", &num);
				if(num >= 1 && num <= 50){
					printf("\nOdd numbers from 1 - %d:\n", num);
					for(i = 1; i <= num; ++i){
						if(odd(i)){
							printf("%d\n", i);
						}
					}
				}
				else{
					printf("\n\nINVALID NUMBER!");
				}
				break;
			case 4:
				system("cls");
				ui1();
				input();
				scanf("%d", &num);
				if(num >= 1 && num <= 50){
					printf("\nEven numbers from 1 - %d:\n", num);
					for(i = 1; i <= num; ++i){
						if(even(i)){
							printf("%d\n", i);
						}
					}
				}
				else{
					printf("\n\nINVALID NUMBER!");
				}
				break;
			case 5:
				break;
			default:
				printf("\nINVALID OPTION!");
				break;
		}
		if(choice != 5){
			printf("\n\nTry Again [Yes/No]?");
			scanf(" %s", again);
		}
	}while(strcmp(again, "Yes") == 0 || strcmp(again, "yes") == 0);
	end();
	return 0;
}
