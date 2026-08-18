#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Student{
    char name[50];
    int q1, q2, q3;
    struct Student* next;
}RECORD;

RECORD *head;

void initialize();
void addRec(char n[], int x1, int x2, int x3);
void delRec(char n[]);
void update(char n[]);
void display();
void save();
void retrieve();
int menu();

int main(){
    char nm[50];
    int x1, x2, x3;

    initialize();

    retrieve();

    while(1){
        int flag = 0;
        RECORD *p =head;
        switch(menu()){
        case 1:
            printf("\n\nENTER NAME: ");
            scanf(" %[^\n]", nm);
            while(p != NULL){
                if(strcmp(nm, p->name) == 0){
                        flag = 1;
                        break;
                }
                p = p->next;
            }
            if(flag){
                printf("\n\nNAME ALREADY EXIST!\n\n");
                system("pause");
                break;
            }
            printf("ENTER QUIZ 1: ");
            scanf("%d", &x1);
            printf("ENTER QUIZ 2: ");
            scanf("%d", &x2);
            printf("ENTER QUIZ 3: ");
            scanf("%d", &x3);

            addRec(nm, x1, x2, x3);
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
            save();
            exit(0);
            break;
        default:
            printf("\n\nINVALID CHOICE!\n\n");
            system("pause");
            break;
        }
    }
}

void initialize(){
    head = NULL;
}

void addRec(char n[], int x1, int x2, int x3){
    system("cls");
    RECORD *p, *q, *newNode;
    p = q = head;
    newNode = (RECORD*) malloc(sizeof(RECORD));
    strcpy(newNode->name, n);
    newNode->q1 = x1;
    newNode->q2 = x2;
    newNode->q3 = x3;

    if(head == NULL || strcmp(n, head->name) < 0){
        newNode->next = head;
        head = newNode;
    }
    else{
        while(p != NULL && strcmp(n, p->name) > 0){
            q = p;
            p = p->next;
        }
        newNode->next = p;
        q->next = newNode;
    }
}

void delRec(char n[]){
    system("cls");
    RECORD *p, *q;
    p = q = head;
    while(p != NULL && strcmp(n, p->name) != 0){
        q = p;
        p = p->next;
    }

    if(p == NULL){
        printf("%s DOES NOT EXIST!\n\n", n);
        printf("PRESS ANY KEY TO RESTART PROCESS...");
        getchar();
    }
    else{
        if(p == head){
            head = p->next;
        }
        else{
            q->next = p->next;
        }
    }
}

void update(char n[]){
    RECORD *p, *q;
    int choice = 0, score;
    float ave;
    p = q = head;

    while(p != NULL && strcmp(n, p->name) != 0){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        printf("%s DOES NOT EXIST!\n\n", n);
        printf("PRESS ANY KEY TO RESTART PROCESS...");
        getchar();
    }
    else{
        while(1){
            system("cls");
            ave = (float)(p->q1+p->q2+p->q3) / 3.0;
            printf("RECORD OF %s\n\n", n);
            printf("%-20s %-6s %-6s %-6s %-8s %-6s", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");

            printf("\n%-20s %-6d %-6d %-6d %-8.2f %-6s", p->name, p->q1, p->q2, p->q3, ave, (ave >= 75) ? "PASSED" : "FAILED");
            printf("\n\nEDIT SCORE\n1. QUIZ 1\n2. QUIZ 2\n3. QUIZ 3\n4. RETURN TO MENU");
            printf("\n\nCHOOSE: ");
            scanf("%d", &choice);
            getchar();

            switch(choice){
            case 1:
                printf("\n\nENTER NEW SCORE: ");
                scanf("%d", &score);
                p->q1 = score;
                system("pause");
                break;
            case 2:
                printf("\n\nENTER NEW SCORE: ");
                scanf("%d", &score);
                p->q2 = score;
                system("pause");
                break;
            case 3:
                printf("\n\nENTER NEW SCORE: ");
                scanf("%d", &score);
                p->q3 = score;
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
    RECORD *p = head;
    int i=1;
    float ave;
    printf("RECORD\n\n");
    printf("%-6s %-20s %-6s %-6s %-6s %-8s %-6s", "NO.", "NAME", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");
    while (p!=NULL){
        ave = (float)(p->q1+p->q2+p->q3)/3.0;
        printf("\n%-6d %-20s %-6d %-6d %-6d %-8.2f %-6s\n", i++, p->name, p->q1, p->q2, p->q3, ave, (ave >=75)? "PASSED":"FAILED");
        p=p->next;
    }system("pause");
}

void save(){
    FILE *fp;
    RECORD *p = head;
        int i;

        fp = fopen("MP9.txt", "w");

        if(fp == NULL){
            printf("FILE ERROR!\n\n");
            system("pause");
        }
        else{
            while(p != NULL){
                fprintf(fp, "%s,%d,%d,%d\n", p->name, p->q1, p->q2, p->q3);
                p = p->next;
            }
        }
    fclose(fp);
}

void retrieve(){
    FILE *fp;
    RECORD *p = head;
    char line[100];
    char nam[50];
    int score1, score2, score3;

    fp = fopen("MP9.txt", "r");

    if(fp == NULL){
        printf("FILE ERROR!\n\n");
        system("pause");
    }
    else{
        while(fgets(line, sizeof(line), fp)){
            sscanf(line, "%[^,],%d,%d,%d", nam, &score1, &score2, &score3);

            addRec(nam, score1, score2, score3);
        }
        fclose(fp);
    }
}

int menu(){
    system("cls");
    int choice = 0;

    printf("MENU\n\n");
    printf("1. ADD\n2. DELETE\n3. UPDATE\n4. DISPLAY\n5. EXIT");
    printf("\n\nCHOOSE [1-5]: ");
    scanf("%d", &choice);
    getchar();

    return choice;
}
