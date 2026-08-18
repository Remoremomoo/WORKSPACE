#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 5

char name[MAX][50];
int val = -1;
int q1[MAX], q2[MAX], q3[MAX];
int locate(char n[]);
int locatePos(char n[]);
int isfull();
int isempty();
void addRecord(char n[], int x1, int x2, int x3);
void delRecorc(char n[]);
void updateRecord(char n[]);
void display();
void save();
void retrieve();
int menu();

int main(){
    char nm[50];
    int quiz1, quiz2, quiz3;

    retrieve();

    while(1){
        switch(menu()){
        case 1:
            printf("\n\nENTER NAME: ");
            scanf("%[^\n]", nm);
            if(locate(nm) > -1){
                printf("\n\nNAME ALREADY EXIST!\n\n");
                system("pause");
            }
            else{
                printf("\nENTER QUIZ 1: ");
                scanf("%d", &quiz1);
                printf("\nENTER QUIZ 2: ");
                scanf("%d", &quiz2);
                printf("\nENTER QUIZ 3: ");
                scanf("%d", &quiz3);

                addRecord(nm, quiz1, quiz2, quiz3);
            }
            break;
        case 2:
            printf("\n\nENTER NAME: ");
            scanf("%[^\n]", nm);

            delRecorc(nm);
            break;
        case 3:
            printf("\n\nENTER NAME: ");
            scanf("%[^\n]", nm);

            updateRecord(nm);
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

int locatePos(char n[]){
    int i;
    for(i = 0; i <= val; i++){
        if(strcmp(n, name[i]) < 0){
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

void save(){
    FILE *fp;
    int i;

    fp = fopen("MP5QUIZ.txt", "w");

    if(fp == NULL){
        printf("FILE ERROR!\n\n");
        system("pause");
    }
    else{
        for(i = 0; i <= val; i++){
            fprintf(fp, "%s,%d,%d,%d\n", name[i], q1[i], q2[i], q3[i]);
        }
        fclose(fp);
    }
}

void retrieve(){
    FILE *fp;
    char line[100];
    char nam[50];
    int score1, score2, score3;

    fp = fopen("MP5QUIZ.txt", "r");

    if(fp == NULL){
        printf("FILE ERROR!\n\n");
        system("pause");
    }
    else{
        while(fgets(line, sizeof(line), fp)){
            sscanf(line, "%[^,],%d,%d,%d", nam, &score1, &score2, &score3);

            addRecord(nam, score1, score2, score3);
        }
        fclose(fp);
    }
}

void addRecord(char n[], int x1, int x2, int x3){
    int p, i;
    system("cls");

    if(isfull()){
        printf("RECORD SHEET IS ALREADY FULL!\n\n");
        system("pause");
    }
    else{
        p = locatePos(n);
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
        printf("%s WAS ADDED!\n\n", n);
        system("pause");
    }
}

void delRecorc(char n[]){
    int p, i;
    system("cls");

    if(isempty()){
        printf("RECORD SHEET IS EMPTY!\n\n");
        system("pause");
    }
    else{
        p = locate(n);

        if(p == -1){
            printf("%s DOES NOT EXIST!\n\n", n);
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
            printf("%s WAS DELETED!\n\n", n);
            system("pause");
        }
    }
}

void updateRecord(char n[]){
    int p, score, choice = 0;
    float ave;
    system("cls");

    if(isempty()){
        printf("RECORD SHEET IS EMPTY!\n\n");
        system("pause");
    }
    else{
        p = locate(n);

        ave = (q1[p] + q2[p] + q3[p])/3.0;

        printf("RECORD OF %s\n\n", n);
        printf("%-20s %-6s %-6s %-6s %-8s %-6s", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");

        printf("\n%-20s %-6d %-6d %-6d %-8.2f %-6s", name[p], q1[p], q2[p], q3[p], ave, (ave >= 75) ? "PASSED" : "FAILED");
        printf("\n\nEDIT SCORE\n1. QUIZ 1\n2. QUIZ 2\n3. QUIZ 3\n4. RETURN TO MENU");
        printf("\n\nCHOOSE: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
        case 1:
            printf("\n\nENTER NEW SCORE: ");
            scanf("%d", &score);
            q1[p] = score;
            system("pause");
            break;
        case 2:
            printf("\n\nENTER NEW SCORE: ");
            scanf("%d", &score);
            q2[p] = score;
            system("pause");
            break;
        case 3:
            printf("\n\nENTER NEW SCORE: ");
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

void display(){
    int i;
    float ave;
    system("cls");

    if(isempty()){
        printf("RECORD SHEET IS EMPTY!\n\n");
        system("pause");
    }
    else{
            printf("RECORD\n\n");
            printf("%-6s %-20s %-6s %-6s %-6s %-8s %-6s", "NO.", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");
            for(i = 0; i <= val; i++){
                ave = (q1[i] + q2[i] + q3[i])/3.0;
                printf("\n%-6d %-20s %-6d %-6d %-6d %-8.2f %-6s\n", i + 1, name[i], q1[i], q2[i], q3[i], ave, (ave >= 75) ? "PASSED" : "FAILED");
            }
            system("pause");
    }
}

int menu(){
    int choice = 0;
    system("cls");

    printf("MENU\n");
    printf("1. ADD A STUDENT RECORD\n2. DELETE A STUDENT RECORD\n3. UPDATE A STUDENT RECORD\n4. DISPLAY ALL RECORD\n5. EXIT");
    printf("\n\nCHOOSE: ");
    scanf("%d", &choice);
    getchar();

    return choice;
}
