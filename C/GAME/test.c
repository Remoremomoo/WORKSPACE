#include <stdio.h>
#include <stdlib.h>

void startMenu(){
	system("color 0b");
	printf("======================================\n");
	printf("              Game Test\n");
	printf("======================================\n\n");
	system("pause");
}
void mainMenu(){
	system("cls");
	printf("MAIN MENU");
	printf("\n1. NEW GAME\n2. LOAD GAME\n3. EXIT");
	printf("\n\nCHOOSE: ");
}
void newGame(){
	system("cls");
	int playerAtk, playerHp, playerLvl, playerDef;
	char playerName[50];
	printf("NEW GAME");
	printf("\n\nEnter your name: ");
	scanf(" %s", playerName);
	
	playerHp = 100;
	playerDef = 10;
	playerLvl = 1;
	playerAtk = 15;
	
	FILE *fsave = fopen("profile.txt", "w");
	
	if(fsave == NULL){
		printf("\nERROR SAVING FILE!\n");
		return;
	}
	
	fprintf(fsave, "%s | %d | %d | %d | %d", playerName, playerHp, playerDef, playerAtk, playerLvl);
	
	fclose(fsave);
	printf("\n\nGAME SAVED!\n");
	
	printf("\nWELCOME PLAYER %s!\n\n", playerName);
	
}
void loadGame(){
	int playerAtk, playerHp, playerLvl, playerDef;
	char playerName[50];
	FILE *fload = fopen("profile.txt", "r");
	
	if(fload == NULL){
		printf("\nPROFILE NOT FOUND!!");
		return;
	}
	fscanf(fload, "%s | %d | %d | %d | %d", playerName, &playerHp, &playerDef, &playerAtk, &playerLvl);
	
	fclose(fload);
	
	printf("\nWELCOME PLAYER %s!\n\n", playerName);
}


int main(){
	int menuChoice;
	char playerName[50];
	startMenu();
	do{
		mainMenu();
		scanf("%d", &menuChoice);
		
		switch(menuChoice){
			case 1:
				newGame();
				system("pause");
				break;
			case 2:
				loadGame();
				system("pause");
				break;
			case 3:
				printf("\n\nEXITING GAME...");
				break;
			default:
				printf("\n\nINVALID CHOICE!!");
				break;
		}
	}while(menuChoice != 3);
	return 0;
}
