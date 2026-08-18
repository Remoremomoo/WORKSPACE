#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 5

char name[MAX][50];
int val = -1;
int q1[MAX], q2[MAX], q3[MAX];
int locate(char n[]);
int locatePos(float n);
int isfull();
int isempty();
int menu();
void addRec(char n[], int x1, int x2, int x3);
void delRec(char n[]);
void update(char n[]);
void display();
void save();
void retrieve();
float average(int x1, int x2, int x3);

int main(){
    char nm[50];
    int quiz1, quiz2, quiz3;

    retrieve();

    while(1){
        switch(menu()){
        case 1:
            printf("\n\nENTER A NAME: ");
            scanf("%[^\n]", nm);

            if(locate(nm) > -1){
                printf("\n\n%s ALREADY EXIST!\n\n", nm);
                system("pause");
            }
            else{
                printf("ENTER QUIZ 1: ");
                scanf("%d", &quiz1);
                printf("ENTER QUIZ 2: ");
                scanf("%d", &quiz2);
                printf("ENTER QUIZ 3: ");
                scanf("%d", &quiz3);

                average(quiz1, quiz2, quiz3);

                addRec(nm, quiz1, quiz2, quiz3);
            }
            break;
        case 2:
            printf("\n\nENTER A NAME: ");
            scanf("%[^\n]", nm);

            delRec(nm);
            break;
        case 3:
            printf("\n\nENTER A NAME: ");
            scanf("%[^\n]", nm);

            update(nm);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n\nSAVING");
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            save();
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

float average(int x1, int x2, int x3){
    float ave;

    ave = (float)(x1 + x2 + x3)/3.0;

    return ave;
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

int locatePos(float n){
    int i;

    for(i = 0; i <= val; i++){
            if(n > average(q1[i],q2[i],q3[i])){
                return i;
            }
    }
    return i;
}

int isfull(){
    return (val == MAX - 1);
}

int isempty(){
    return (val == -1);
}

void addRec(char n[], int x1, int x2, int x3){
    int i, p;
    float ave;

    system("cls");

    if(isfull()){
        printf("RECORD SHEET FULL!\n\n");
        system("pause");
    }
    else{
        ave = (float)(x1+x2+x3)/3.0;
        p = locatePos(ave);
        if(p == -1){
            printf("AVERAGE DOES NOT HAVE A VALUE!\n\n");
            system("cls");
        }
        else{
            val++;
            for(i = val; i >= p; i--){
                strcpy(name[i + 1], name[i]);
                q1[i + 1] = q1[i];
                q2[i + 1] = q2[i];
                q3[i + 1] = q3[i];
            }
            strcpy(name[p], n);
            q1[p] = x1;
            q2[p] = x2;
            q3[p] = x3;
        }
    }
}

void delRec(char n[]){
    int p, i;

    system("cls");

    if(isempty()){
        printf("RECORD SHEET EMPTY!\n\n");
        system("cls");
    }
    else{
        p = locate(n);
        if(p == -1){
            printf("NAME DOES NOT EXIST!\n\n");
            system("pause");
        }
        else{
            for(i = p; i <= val; i++){
                strcpy(name[i], name[i + 1]);
                q1[i] = q1[i + 1];
                q2[i] = q2[i + 1];
                q3[i] = q3[i + 1];
            }
            val--;
        }
    }
}

void update(char n[]){
    int p, choice = 0, score;
    float ave;

    system("cls");

    if(isempty()){
        printf("RECORD SHEET EMPTY!\n\n");
        system("pause");
    }
    else{
        p = locate(n);
        if(p == -1){
            printf("NAME DOES NOT EXIST!\n\n");
            system("pause");
        }
        else{
            while(1){
                system("cls");
                printf("RECORD OF %s:\n\n", n);
                printf("%-20s %-6s %-6s %-6s %-6s %-6s", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");

                ave = average(q1[p], q2[p], q3[p]);

                printf("\n%-20s %-6d %-6d %-6d %-6.2f %-6s", name[p], q1[p], q2[p], q3[p], ave, ave > 75 ? "PASSED" : "FAILED");
                printf("\n\nEDIT SCORE: \n1. QUIZ 1\n2. QUIZ 2\n3. QUIZ 3\n4. RETURN TO MENU");
                printf("\n\nCHOOSE: ");
                scanf("%d", &choice);
                getchar();

                switch(choice){
                case 1:
                    printf("ENTER NEW SCORE: ");
                    scanf("%d", &score);

                    q1[p] = score;
                    break;
                case 2:
                    printf("ENTER NEW SCORE: ");
                    scanf("%d", &score);

                    q2[p] = score;
                    break;
                case 3:
                    printf("ENTER NEW SCORE: ");
                    scanf("%d", &score);

                    q3[p] = score;
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
            save();
            retrieve();
        }
    }
}

void display(){
    int i;
    float ave;

    system("cls");

    if(isempty()){
        printf("RECORD SHEET EMPTY!\n\n");
        system("pause");
    }
    else{
        printf("RECORDS\n\n");
        printf("%-6s %-20s %-6s %-6s %-6s %-6s %-6s\n", "NO.", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");
        for(i  = 0; i <= val; i++){
            ave = average(q1[i], q2[i], q3[i]);
            printf("%-6d %-20s %-6d %-6d %-6d %-6.2f %-6s\n\n", i + 1, name[i], q1[i], q2[i], q3[i], ave, ave > 75 ? "PASSED" : "FAILED");
        }
        system("pause");
    }
}

void save(){
    FILE *fp;
    int i;

    fp = fopen("MP7REC.txt", "w");

    if(fp == NULL){
        printf("FILE ERROR!\n\n");
        system("pause");
    }
    else{
        for(i = 0; i <= val; i++){
            fprintf(fp, "%s,%d,%d,%d\n", name[i], q1[i], q2[i], q3[i]);
        }
    }
    fclose(fp);
}

void retrieve(){
    FILE *fp;
    char line[100];
    char nam[50];
    int score1, score2, score3;

    fp = fopen("MP7REC.txt", "r");

    int val = -1;

    if(fp == NULL){
        printf("FILE ERROR!\n\n");
        system("pause");
    }
    else{
        while(fgets(line, sizeof(line), fp)){
            sscanf(line, "%[^,],%d,%d,%d", nam, &score1, &score2, &score3);
            addRec(nam, score1, score2, score3);
        }
    }
    fclose(fp);
}

int menu(){
    int choice = 0;

    system("cls");

    printf("MENU\n");
    printf("1. ADD A RECORD\n2. DELETE A RECORD\n3. UPDATE A RECORD\n4. DISPLAY ALL RECORD\n5. EXIT");
    printf("\n\nCHOOSE: ");
    scanf("%d", &choice);
    getchar();

    return choice;
}
