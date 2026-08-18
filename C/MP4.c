#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int q1[MAX], q2[MAX], q3[MAX];
int val = -1;
char name[MAX][50];
int locate(char n[]);
int isfull();
int isempty();
void addRecord(char n[], int x1, int x2, int x3);
void delRecord(char n[]);
void update(char n[]);
void display();
void display2(char n[]);
int menu();
void ui();
void save();
void retri();

int main(){
    int quiz1, quiz2, quiz3;
    char nm[50];

    retri();

    ui();

    while(1){
        switch(menu()){
        case 1:
            printf("\n\nENTER A NAME: ");
            scanf(" %[^\n]", nm);
            if(locate(nm) > -1){
                printf("\n\nNAME ALREADY RECORDED!\n\n");
                system("pause");
            }
            else{
                printf("ENTER QUIZ 1: ");
                scanf("%d", &quiz1);
                printf("ENTER QUIZ 2: ");
                scanf("%d", &quiz2);
                printf("ENTER QUIZ 3: ");
                scanf("%d", &quiz3);

                addRecord(nm, quiz1, quiz2, quiz3);

                printf("%s SUCCESSFULLY RECORDED!\n\n", nm);
                system("pause");
            }
            break;
        case 2:
            printf("\n\nENTER A NAME: ");
            scanf(" %[^\n]", nm);
            delRecord(nm);
            break;
        case 3:
            printf("\n\nENTER A NAME: ");
            scanf(" %[^\n]", nm);
            display2(nm);
            break;
        case 4:
            display();
            system("pause");
            break;
        case 5:
            printf("\n\nSAVING...\n\n");
            save();
            system("pause");
            exit(0);
            break;
        default:
            printf("\n\nINVALID CHOICE!!\n\n");
            system("pause");
            break;

        }
    }

    return 0;
}

int locate(char n[]){
    int i;

    for(i = 0; i <= val; i++){
        if(strcmp(name[i], n) == 0){
         return i;
        }
    }
    return -1;
}
int isempty(){
    return (val == -1);
}
int isfull(){
    return (val == MAX - 1);
}
void ui(){
    system("cls");
    printf("----------------------------------------------");
    printf("\n%30s", "RECORDS V4 (MP4)");
    printf("\n----------------------------------------------\n\n");
    system("pause");
}
int menu(){
    int choice = 0;
    system("cls");

    printf("MENU");
    printf("\n1. ADD A RECORD\n2. DELETE A RECORD\n3. UPDATE RECORD\n4. DISPLAY\n5. EXIT\n");
    printf("CHOOSE [1-5]: ");
    scanf("%d", &choice);
    getchar();

    return choice;
}
void addRecord(char n[], int x1, int x2, int x3){
    system("cls");

    if(isfull()){
        printf("RECORD ALREADY FULL!\n\n");
        system("pause");
    }
    else{
        val++;
        q1[val] = x1;
        q2[val] = x2;
        q3[val] = x3;
        strcpy(name[val], n);
    }
}
void delRecord(char n[]){
    int p, i;
    system("cls");

    p = locate(n);

    if(p == -1){
        printf("NAME DOES NOT EXIST!\n\n");
        system("pause");
    }
    else{
        for(i = p; i <= val; i++){
            q1[i] = q1[i + 1];
            q2[i] = q2[i + 1];
            q3[i] = q3[i + 1];
            strcpy(name[i], name[i + 1]);
        }
        val--;
        printf("%s WAS DELETED FROM THE RECORD!\n\n", n);
        system("pause");
    }
}
void display2(char y[]){
    int p, i, choice = 0;
    float ave;

    system("cls");

    if(isempty()){
        printf("NAME DOES NOT EXIST!\n\n");
        system("pause");
    }
    else{
        int score;
        p = locate(y);

        while(1){
        system("cls");
        printf("RECORD OF %s", y);
        printf("\n%-20s %-6s %-6s %-6s %-8s", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE");

        printf("\n%-20s %-6d %-6d %-6d %-8.2f", name[p], q1[p], q2[p], q3[p], ave = (q1[p] + q2[p] + q3[p]) / 3.00);
        printf("\n\nCHOOSE QUIZ TO UPDATE:\n1. QUIZ 1\n2. QUIZ 2\n3. QUIZ 3\n4. RETURN TO MENU");
        printf("\n\nCHOOSE [1-4]: ");
        scanf("%d", &choice);

            switch(choice){
            case 1:
                printf("ENTER NEW SCORE: ");
                scanf("%d", &score);
                q1[p] = score;
                system("pause");
                break;
            case 2:
                printf("ENTER NEW SCORE: ");
                scanf("%d", &score);
                q2[p] = score;
                system("pause");
                break;
            case 3:
                printf("ENTER NEW SCORE: ");
                scanf("%d", &score);
                q3[p] = score;
                system("pause");
                break;
            case 4:
                return;
                break;
            default:
                printf("\n\nINVALID CHOICE!\n\n");
                system("pause");
                break;
            }
        }
    }
}
void display(){
    int i;
    float ave;
    system("cls");

    if(isempty()){
        printf("RECORD SHEET IS EMPTY!\n\n");
        system("pause");
    }
    printf("RECORDS");
        printf("\n%-4s %-20s %-6s %-6s %-6s %-8s", "NO.", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE");

        for(i = 0; i <= val; i++){
            printf("\n%-4d %-20s %-6d %-6d %-6d %-8.2f", i + 1, name[i], q1[i], q2[i], q3[i], ave = (q1[i] + q2[i] + q3[i]) / 3.00);
        }
}
void save(){
    FILE *fp;
    int i;

    fp = fopen("RECORD.txt", "w");

    if(fp == NULL){
        printf("FILE ACCESS ERROR!");
        system("pause");
    }
    else{
        for(i = 0; i <= val; i++){
            fprintf(fp, "%s,%d,%d,%d\n", name[i], q1[i], q2[i], q3[i]);
        }
        fclose(fp);
    }
}
void retri(){
    FILE *fp;
    char line[100];
    char nm[50];
    int qui1, qui2, qui3;

    fp = fopen("RECORD.txt", "r");

    if(fp == NULL){
        printf("FILE ACCESS ERROR!\n\n");
        system("pause");
    }
    else{
        while(fgets(line, sizeof(line), fp)){
            sscanf(line, "%[^,], %d, %d, %d", nm, &qui1, &qui2, &qui3);
            addRecord(nm, qui1, qui2, qui3);
        }
        fclose(fp);
    }
}
