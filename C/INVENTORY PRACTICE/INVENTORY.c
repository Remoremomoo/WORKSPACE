#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	FILE *fstock;
	int a[10], x, y, z, action, i;
	char name[50];
	char itemName[10][50];//for 10 boxes, pwede ka maglagay ng name up to 50 characters
	
	fstock = fopen("stock.txt", "a");//append "a" pra makagawa sya ng file if wala pang txt file
	if(fstock == NULL){
		printf("ERROR OPENING FILE!");
		printf("\n\nCLOSING...");
		sleep(2);
		return 1;
	}
	
	for(i = 0; i < 10; i++){//iseset nia ung laman ng boxes to 0 sa start.
		a[i] = 0;
		strcpy(itemName[i], "");//iseset nia lahat ng names ng boxes to empty string.
		//hindi pwedeng itemName[i] = "" kse array of characters sya
		//strcpy pra icocopy nia ung iinput mong name sa case 1 papuntang sinelect mong box.
	}
	
	fstock = fopen("stock.txt", "r");//read mode ung pointer ngaun "r"
	if(fstock != NULL){
		for(i = 0; i < 10; i++){
			if(fscanf(fstock, "%s %d", itemName[i], &a[i]) != 2){//fscanf is babasahin nia lahat ng nkasave sa txt file with a format: itemName QTY
				strcpy(itemName[i], "");//!=2 ibig sabihin pag may error or empty line, magrereset sya sa empty
				a[i] = 0;
			}
		}
		fclose(fstock);//pang close ng file pra d magkaissue. uutusan mo ung fstock na iclose.
	}
	do{//basic do-while loop kung gustong umulit ung buong process
		system("cls");
		printf("-----| INVENTORY |-----");
		printf("\n\nACTIONS:");
		printf("\n1. RE-STOCK\n2. PULL-OUT\n3. INVENTORY CHECK\n4. EXIT");
		printf("\n\nCHOOSE: ");
		scanf("%d", &action);
		
		switch(action){
			case 1://case 1 is pag magrerestock ng item.
				system("cls");
				printf("-----| RE-STOCK |-----");
				printf("\n\nCURRENT STOCKS\n");
				for(i = 0; i < 10; i++){//itong for loop is pra sa box 0-9
					if(a[i] == 0){//if-else pra pag may laman, ung else ung piprint. pag wala, ung if
						printf("BOX #%d: EMPTY (QTY: 0)\n", i);
					}
					else{
						printf("BOX #%d: %s (QTY: %d)\n", i, itemName[i], a[i]);
					}
				}
				
				printf("\nCHOOSE BOX # TO RE-STOCK (0-9): ");
				scanf("%d", &x);//eto, pipili ka ng box number from 0-9 na lalagyan mo
				
				if(x < 0 || x > 9){//pag wla sa 0-9 ung ininput mo
					printf("\nINVALID BOX #!");
					printf("\nPress any key to return...");
					system("pause");
					break;
				}
				printf("\n\nENTER ITEM NAME: ");
				scanf(" %s", itemName[x]);//enter ka ng name sa pinili mong box # (ung x)
				
				printf("\n\nENTER QUANTITY TO ADD: ");
				scanf("%d", &y);//magbibigay ka ng number ng irerestock mo
				
				a[x] += y;//add and magiging bagong value ng box number x.
				
				fstock = fopen("stock.txt", "w");//nkawrite mode
				for(i = 0; i < 10; i++){//for loop pra magshow ung boxes 0-9
					if(a[i] > 0 && strcmp(itemName[i], "") != 0){//condition pag ung value ng box is not less than 0 and ung name is not empty string, ay hindi true
						fprintf(fstock, "%s %d\n", itemName[i], a[i]);
					}
					else{
						fprintf(fstock, "EMPTY 0\n");
					}
				}
				fclose(fstock);
				
				printf("\n\nUPDATED!\n");
				printf("BOX #%d: %s (QTY: %d)\n\n", x, itemName[x], a[x]);	//piprint lang ung box na sinelect	
																			//pati ung quantity neto.
				system("pause");
				break;
				
			case 2:
				system("cls");
				printf("-----| PULL-OUT |-----");
				printf("\n\nCURRENT STOCKS\n");//same as case 1 pero baliktad naman
				for(i = 0; i < 10; i++){
					if(a[i] == 0){
						printf("BOX #%d: EMPTY (QTY: 0)\n", i);
					}
					else{
						printf("BOX #%d: %s (QTY: %d)\n", i, itemName[i], a[i]);
					}
				}
				
				printf("\nCHOOSE BOX # TO PULL-OUT (0-9): ");
				scanf("%d", &x);
				if(x < 0 || x > 9){
					printf("\nINVALID BOX #!");
					printf("\nPress any key to return...");
					system("pause");
					break;
				}//pag select mo ng box #, d kana maglalagay ulet ng name kse meron na
				printf("\n\nENTER QUANTITY TO GET: ");
				scanf("%d", &y);
				
				if(y > a[x]){
					printf("\n\nWARNING: NOT ENOUGH STOCK! PULLING OUT REMAINING %d ITEMS...\n", a[x]);
					a[x] = 0;
				}
				else{
					a[x] -= y;//ibbabawas nia sa current value nung box na un.
				}
				
				fstock = fopen("stock.txt", "w");//same lang as sa case 1
				for(i = 0; i < 10; i++){
					if(a[i] > 0 && strcmp(itemName[i], "") != 0){
						fprintf(fstock, "%s %d\n", itemName[i], a[i]);
					}
					else{
						fprintf(fstock, "EMPTY 0\n");
					}
				}
				fclose(fstock);
				
				
				printf("\n\nUPDATED!\n");
				printf("BOX #%d: %s (QTY: %d)\n\n", x, itemName[x], a[x]);	
				
				system("pause");
				break;
			case 3:
				system("cls");
				printf("-----| INVENTORY CHECK |-----");
				printf("\n\nCURRENT STOCKS\n");
				for(i = 0; i < 10; i++){
					if(a[i] == 0 || strcmp(itemName[i], "")==0){
						printf("BOX #%d: EMPTY (QTY: 0)\n", i);
					}
					else{
						printf("BOX #%d: %s (QTY: %d)\n", i, itemName[i], a[i]);
					}//ipapakita nia lang lahat ng boxes and kung may mga name ba to or quantity
				}
				
				system("pause");
				break;
			case 4:
				printf("\n\nTHANK YOU FOR USING INVENTORY!");
				break;
			default:
				printf("\n\nINVALID ACTION!");
				break;
		}	
	}while(action != 4);
	printf("\n\nCLOSING TERMINAL...");
	fclose(fstock);
	return 0;
	
}
