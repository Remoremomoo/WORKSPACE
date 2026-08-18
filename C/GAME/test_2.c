#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void title(){
    printf("-------------------------------------------------");
    printf("\n\n\t\t    TEST GAME");
    printf("\n\n-------------------------------------------------\n\n");
}
void mainMenu(){
    printf("MAIN MENU");
    printf("\n1. NEW GAME\n2. LOAD GAME\n3. EXIT");
}

int main(){
    title();
    system("pause");
    system("cls");
    mainMenu();


    return 0;
}
