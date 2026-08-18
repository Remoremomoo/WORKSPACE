#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

char name[MAX][50];
int q1[MAX], q2[MAX], q3[MAX];
int val = -1;
int locate(char y[]);
int full();
int empty();
void add(char y[], int x1, int x2, int x3);
void del(char y[]);
void disp();
void ui();
int menu();

int main(){
    int quiz1, quiz2, quiz3;
    char n[50];

    ui();

    while(1){
        switch(menu()){
        case 1:
            printf("\n\nINPUT A NAME: ");
            scanf(" %[^\n]", n);
            printf("INPUT Q1 Q2 Q3: ");
            scanf("%d %d %d", &quiz1, &quiz2, &quiz3);
            add(n, quiz1, quiz2, quiz3);
            break;
        case 2:
            printf("\n\nINPUT A NAME: ");
            scanf(" %[^\n]", n);
            del(n);
            break;
        case 3:
            disp();
            break;
        case 4:
            printf("\n\nTHANK YOU FOR USING!\n\n");
            exit(0);
            break;
        default:
            printf("\n\nINVALID CHOICE!\n\n");
            system("pause");
            break;
        }
    }

    return 0;
}

int locate(char y[]){
    int i;
    for(i = 0; i <= val; i++){
        if(strcmp(name[i], y) == 0){
            return i;
        }
    }
    return -1;
}

int full(){
    return (val == MAX - 1);
}

int empty(){
    return (val == -1);
}

void add(char y[], int x1, int x2, int x3){
    system("cls");
    if(full()){
        printf("\n\nRECORD IS FULL!\n\n");
        system("pause");
    }
    else{
        val++;
        strcpy(name[val], y);
        q1[val] = x1;
        q2[val] = x2;
        q3[val] = x3;
        printf("\n\nRECORD OF %s HAS BEEN ADDED!\n\n", y);
        system("pause");
    }
}

void del(char y[]){
    int p, i;
    system("cls");
    p = locate(y);

    for(i = 0; i <= val; i++){
        strcpy(name[i], name[i + 1]);
    }
    val--;
    printf("\n\nRECORD OF %s HAS BEEN DELETED!\n\n", y);
    system("pause");
}

void disp(){
    int i;
    system("cls");
    if(empty()){
        printf("\n\nRECORD IS EMPTY!\n\n");
        system("pause");
    }
    else{
        printf("RECORD");
        printf("\n%-4s %-20s %-8s %-8s %-8s %-8s", "NO. ", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "REMARKS");

        for(i = 0; i <= val; i++){
            printf("\n%-4d %-20s %-8d %-8d %-8d %-8s\n\n", i + 1, name[i], q1[i], q2[i], q3[i], (q1 >= 10 && q2 >= 10 && q3 >= 10) ? "PASSED" : "FAILED");

        }
        system("pause");
    }
}

int menu(){
    int choice;
    system("cls");
    printf("MENU");
    printf("\n1. ADD A RECORD\n2. DELETE A RECORD\n3. DISPLAY ALL RECORDS\n4. EXIT");
    printf("\n\nCHOOSE [1-4]: ");
    scanf("%d", &choice);

    return choice;
}

void ui(){
    printf("--------------------------\n");
    printf("%13s", "RECORDS");
    printf("\n--------------------------\n\n");
    system("pause");
}
