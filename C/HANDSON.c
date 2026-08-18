#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

int num[MAX];
char name[MAX][50];
int val = -1;
void addRec();
void delRec();
int locate();
int full();
int empty();
int display();
void overlay();


int main(){
        int x;
        char name[50];

        overlay();
        while(1){
            switch(display()){
                case 1:
                    printf("\n\nENTER NAME: ");
                    scanf(" %[^\n]", name);
                    printf("ENTER GRADE: ");
                    scanf("%d", &x);
                    addRec(name, x);
                    break;
                case 2:
                    printf("\n\nENTER NAME: ");
                    scanf(" %[^\n]", name);
                    printf("ENTER GRADE: ");
                    scanf("%d", &x);
                    delRec(name, x);
                    break;
            }
            getchar();
    }
}

void overlay(){
    printf("---------------------");
    printf("\n %13s", "RECORDS");
    printf("\n---------------------\n\n");
    system("pause");
}
int display(){
    int choice;
    system("cls");
    printf("MENU");
    printf("\n1. ADD RECORD\n2. DELETE RECORD\n3. DISPLAY ALL RECORDS\n4. RESET ALL RECORDS\n5. EXIT");
    printf("\n\nCHOOSE [1-5]: ");
    scanf("%d", &choice);

    return choice;
}
int full(){
    return (val == MAX - 1);
}
int empty(){
    return (val == -1);
}
void addRec(char y[], int x){
    if(full()){
        printf("\n\nLIST IS FULL!\n\n");
        system("pause");
    }
    else{
        val++;
        strcpy(name[val], y);
        num[val] = x;
        system("pause");
    }
}
void delRec(char y[], int x){
    int p, i;
    if(empty()){
        printf("\n\nLIST IS EMPTY!\n\n");
        system("pause");
    }
    else{
        p = locate(y, x);
        if(p == -1){
            printf("\n\nRECORD DOES NOT EXIST!\n\n");
            system("pause");
        }
        else{
            for(i = 0; i < val; i++){
                num[i] = num[i + 1];
                strcpy(name[i], name[i + 1]);
            }
            val--;
            printf("\n\nRECORD FOR %s HAS BEEN DELETED!", y);
            system("pause");
        }
    }
}
int locate(char y[], int x){
    int i;
    for(i = 0; i <= val; i++){
        if(num[i] == x && strcmp(name[i], y) == 0){
            return i;
        }
    }
    return -1;
}
