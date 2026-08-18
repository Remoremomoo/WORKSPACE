#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct pokemon{
	char pokemonName[20];
	int hp;
	int lvl;
	int atk;
	int def;
};
void titleScreen(){
	printf("====================");
	printf("\nPOKEMON RED\n");
	printf("====================");
	printf("\n1. START GAME\n2. VIEW STATS\n3. EXIT");
	printf("\n\nSELECT YOUR CHOICE: ");
}
void choosePokemon(struct pokemon *p){
	int choice, valid = 0;
	
	while(!valid){
	printf("CHOOSE YOUR POKEMON:");
	printf("\n1. Charmander\n2. Bulbasaur\n3. Squirtle\n4. Pikachu");
	printf("\n\nENTER CHOICE: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			strcpy(p->pokemonName, "Charmander");
			p->hp = 39;
			p->lvl = 1;
			p->atk = 52;
			p->def = 43;
			valid = 1;
			break;
		case 2:
			strcpy(p->pokemonName, "Bulbasaur");
			p->hp = 45;
			p->lvl = 1;
			p->atk = 49;
			p->def = 49;
			valid = 1;
			break;
		case 3:
			strcpy(p->pokemonName, "Squirtle");
			p->hp = 44;
			p->lvl = 1;
			p->atk = 48;
			p->def = 65;
			valid = 1;
			break;
		case 4:
			strcpy(p->pokemonName, "Pikachu");
			p->hp = 35;
			p->lvl = 1;
			p->atk = 55;
			p->def = 40;
			valid = 1;
			break;
		default:
			printf("INVALID CHOICE! CHOOSE AGAIN.\n");
			break;
	}
}
	printf("YOU CHOSE %s\n", p->pokemonName);
}

int main(){
	int menuChoice;
	struct pokemon p;
	
	while(menuChoice != 3){
		titleScreen();
		scanf("%d", &menuChoice);
		
		switch(menuChoice){
			case 1:
				choosePokemon(&p);
				printf("BATTLE WILL START SOON...\n");
				break;
			case 2:
				printf("YOUR POKEMON: %s | LVL: %d | HP: %d | ATK: %d | DEF: %d\n", p.pokemonName, p.lvl, p.hp, p.atk, p.def);
				break;
			case 3:
				printf("EXITING GAME. BYE!\n");
				break;
			default:
				printf("INVALID CHOICE! TRY AGAIN\n");
				break;
		}
	}
	return 0;
}

