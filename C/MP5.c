#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 5

char name[MAX][50];
int val = -1;
int q1[MAX], q2[MAX], q3[MAX];
int locate(char n[]);
int full();
int empty();
int menu();
void addRec(char n[], int x1, int x2, int x3);
void delRec(char n[]);
void display();
void update(char n[]);
void ui();
void save();
void retrieve();

int main(){
    char nm[50];
    int quiz1, quiz2, quiz3;

    retrieve();

    ui();

    while(1){
        switch(menu()){
        case 1:
            printf("\n\nENTER NAME: ");
            scanf(" %[^\n]", nm);
            if(locate(nm) > -1){
                printf("\n\nNAME ALREADY EXIST!\n\n");
                system("pause");
            }
            else{
                printf("ENTER QUIZ 1: ");
                scanf("%d", &quiz1);
                printf("ENTER QUIZ 2: ");
                scanf("%d", &quiz2);
                printf("ENTER QUIZ 3: ");
                scanf("%d", &quiz3);

                addRec(nm, quiz1, quiz2, quiz3);
            }
            break;
        case 2:
             printf("\n\nENTER NAME: ");
             scanf(" %[^\n]", nm);
             delRec(nm);
             break;
        case 3:
             printf("\n\nENTER NAME: ");
             scanf(" %[^\n]", nm);
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
        }
    }


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

int full(){
    return (val == MAX - 1);
}

int empty(){
    return (val == -1);
}

int menu(){
    int choice = 0;
    system("cls");

    printf("MENU\n");
    printf("1. ADD A RECORD\n2. DELETE A RECORD\n3. UPDATE A RECORD\n4. DISPLAY ALL RECORD\n5. EXIT\n\n");
    printf("CHOOSE: ");
    scanf("%d", &choice);

    getchar();

    return choice;
}

void addRec(char n[], int x1, int x2, int x3){
    system("cls");

    if(full()){
        printf("RECORD SHEET IS FULL!\n\n");
        system("pause");
    }
    else{
        val++;
        strcpy(name[val], n);
        q1[val] = x1;
        q2[val] = x2;
        q3[val] = x3;
    }
}

void delRec(char n[]){
    int p, i;

    if(empty()){
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
            printf("%s WAS DELETED FROM THE RECORD SHEET!\n\n", n);
            system("pause");
        }
    }
}

void update(char n[]){
    int p, ch = 0, score;
    float ave;
    system("cls");

    p = locate(n);

    if(p == -1){
        printf("%s DOES NOT EXIST!\n\n", n);
        system("pause");
    }
    else{
        while(1){
                system("cls");

        printf("RECORD OF %s\n\n", n);
        printf("%-20s %-6s %-6s %-6s %-8s %-6s", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");

        printf("\n%-20s %-6d %-6d %-6d %-8.2f %-6s", name[p], q1[p], q2[p], q3[p], ave = (q1[p] + q2[p] + q3[p])/3.0, ave >= 7? "PASSED" : "FAILED");
        printf("\n\nEDIT SCORE \n1. QUIZ 1\n2. QUIZ 2\n3. QUIZ 3\n4. RETURN TO MENU\n\nCHOOSE  ");
        scanf("%d", &ch);

            switch(ch){
            case 1:
                printf("\n\nENTER NEW SCORE: ");
                scanf("%d", &score);

                q1[p] = score;
                break;
            case 2:
                printf("\n\nENTER NEW SCORE: ");
                scanf("%d", &score);

                q2[p] = score;
                break;
            case 3:
                printf("\n\nENTER NEW SCORE: ");
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
    }
}

void display(){
    int i;
    float ave;

    system("cls");

    if(empty()){
        printf("EMPTY RECORD SHEET!\n\n");
        system("pause");
    }
    else{
        printf("RECORD SHEET\n\n");
    printf("%-6s %-20s %-6s %-6s %-6s %-8s %-6s", "NO.", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");
        for(i = 0; i <= val; i++){
            ave = (q1[i] + q2[i] + q3[i])/3.0;
            printf("\n%-6d %-20s %-6d %-6d %-6d %-8.2f %-6s\n\n", i + 1, name[i], q1[i], q2[i], q3[i], ave, (ave >= 7) ? "PASSED" : "FAILED");
        }
        system("pause");
    }
}

void save(){
    FILE *fp;
    int i;
    float ave;

    fp = fopen("REC.txt", "w");

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
    char line[80];
    char fn[50];
    int score1, score2, score3;

    fp = fopen("REC.txt", "r");

    if(fp == NULL){
        printf("FILE ERROR!\n\n");
        system("pause");
    }
    else{
        while(fgets(line, sizeof(line), fp)){
            sscanf(line, "%[^,],%d,%d,%d", fn, &score1, &score2, &score3);

            addRec(fn, score1, score2, score3);
        }
        fclose(fp);
    }
}

void ui(){
    system("cls");
    printf("---------------------------------\n");
    printf("%-10s", "RECORD SHEET V5 (MP5)\n");
    printf("---------------------------------\n\n");
    system("pause");
}
