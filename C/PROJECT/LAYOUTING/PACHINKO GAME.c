#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef struct User{
    char name[50];
    int password, points, addPoints, subPoints, mulPoints, divPoints;
    struct User* next;
}USER;

USER *head;
USER *currentUser;


void initialize();
void sort();
int login(char n[], int x);
int regi(char n[], int x, int pts, int add, int sub, int mul, int div);
int mainMenu();
void gotoxy (int x, int y);
void leaderboard();
void menu();
void ui();
int question();
int scenario(int *r, int *opType);
int numberRoll(int luck);
int scoring(int x);
void game();
void tempRemove(char n[]);
void save();
void retrieve();

int main(){
    int x;

    initialize();
    retrieve();
    ui();


    while(1){
        menu();

        int exitMenu = 0;
        while(exitMenu == 0){
            int choice = mainMenu();

            switch(choice){
            case 0:
                if(currentUser == NULL){
                    system("pause");
                }
                else{
                    game();
                }
                break;
            case 1:
                leaderboard();
                break;
            case 2:
                currentUser = NULL;
                exitMenu = 1;
                break;
            }
        }
    }

    return 0;
}

void initialize(){
    head = NULL;
    currentUser = NULL;
}

void ui(){
    printf("%93s", "====================================================================");//TITLE UI
    printf("\n%70s", "#ARITHMETIC PACHINKO#");
    printf("\n%93s", "====================================================================");

    printf("\n\n%72s", "Test your SKILL and LUCK!");
    printf("\n\n%79s", "Answer arithmetic questions to increase");
    printf("\n%77s", "your LUCK and hit the JACKPOT (777)");

    printf("\n\n%93s", "--------------------------------------------------------------------");

    printf("\n");
    while(!_kbhit()){
        printf("\r%50sPRESS ENTER TO START", "");
        fflush(stdout);
        sleep(1);

        printf("\r%50s                                      ", "");
        fflush(stdout);
        sleep(1);

    }
    getchar();

}

void menu(){
    system("cls");
    while(1){
            system("cls");
        int flag = 0;
        int choice = 0, pass;
        char nm[50];

        printf("\n\n\n%93s", "====================================================================");
        printf("\n%66s", "---|MENU|---");
        printf("\n\n%65s", "1. REGISTER");
        printf("\n%63s", "2. LOGIN");
        printf("\n%63s", "3. EXIT");
        printf("\n%93s", "====================================================================");
        printf("\n\n%62s", "CHOOSE: ");
        scanf("%d", &choice);
        getchar();
        USER *p = head;
        switch(choice){
        case 1:
            printf("\n\n%65s", "ENTER USERNAME: ");
            scanf(" %[^\n]", nm);
            getchar();
            while(p != NULL){
                if(strcmp(nm, p->name) == 0){
                    flag = 1;
                    break;
                }
                p = p->next;
            }
            if(flag){
                printf("\n\n%72s", "USERNAME ALREADY EXISTED!");
                getchar();
                break;
            }
            printf("\n%65s", "ENTER PASSWORD: ");
            scanf("%d", &pass);
            getchar();
            if(regi(nm, pass, 0, 0, 0, 0, 0)){
                login(nm, pass);
                save();
                printf("\n%70s", "REGISTERED SUCCESFULL!");
                printf("\n\n\n%44s", "");
                printf("===PRESS ENTER TO CONTINUE===");
                getchar();
                return;
            }
            break;
        case 2:
            printf("\n\n%65s", "ENTER USERNAME: ");
            scanf(" %[^\n]", nm);
            printf("\n%65s", "ENTER PASSWORD: ");
            scanf("%d", &pass);
            getchar();
            if(login(nm, pass)){
                printf("\n%67s", "LOGIN SUCCESFULL!");
                printf("\n\n\n%44s", "");
                printf("===PRESS ENTER TO CONTINUE===");
                getchar();
                return;
            }
            break;
        case 3:
            printf("\n\n%64s", "CLOSING...");
            sleep(1);
            exit(0);
            break;
        default:
            printf("\n\n%68s", "INVALID CHOICE!\n\n");
            printf("%45s", "");
            system("pause");
            break;
        }
    }
}

int login(char n[], int x){
    USER *p, *q;
    p = q = head;

    while(p != NULL){
        if(strcmp(n, p->name) == 0 && x == p->password){
            currentUser = p;
            return 1;
        }
        p = p->next;
    }
    printf("\n\n%73s", "ACCOUNT DOES NOT EXIST!\n\n");
    printf("%73s", "PRESS ENTER TO CONTINUE...");
    getchar();
    return 0;
}

int regi(char n[], int x, int pts, int add, int sub, int mul, int div){
    USER *newNode;
    newNode = (USER*) malloc(sizeof(USER));
    strcpy(newNode->name, n);
    newNode->password = x;
    newNode->points = pts;
    newNode->addPoints = add;
    newNode->subPoints = sub;
    newNode->mulPoints = mul;
    newNode->divPoints = div;
    newNode->next = NULL;


    if(head == NULL || newNode->points > head->points){
        newNode->next = head;
        head = newNode;
        return 1;
    }

    USER *p = head;
    while(p->next != NULL && p->next->points >= newNode->points){
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;

    return 1;
}

void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

int mainMenu(){
    int choice = 0;
    int key;

    while(1){
        system("cls");

        printf("\n\n\n");
        printf("               ==== MAIN MENU ====\n\n");

        for(int i = 0; i < 3; i++){
            gotoxy(15, 6 + i);

            if(i == choice){
                printf(" > ");
            } else {
                printf("   ");
            }

            if(i == 0) printf("START GAME");
            if(i == 1) printf("VIEW LEADERBOARD");
            if(i == 2) printf("EXIT");
        }

        key = _getch();

        if(key == 224){
            key = _getch();

            if(key == 72){
                choice--;
                if(choice < 0) choice = 2;
            }
            else if(key == 80){
                choice++;
                if(choice > 2) choice = 0;
            }
        }
        else if(key == 13){
            return choice;
        }
    }
}

void leaderboard(){
    USER *p = head;
    system("cls");
    int rank = 1;

    printf("%93s", "--------------------------------------------------------------------");
    printf("\n%77s", "=========== LEADERBOARD ===========");
    printf("\n%15s %10s %10s %10s %10s %10s %10s", "RANK\t", "NAME\t", "\tPOINTS\t", "ADD\t", "SUB\t", "MUL\t", "DIV\n");

    while(p != NULL && rank <= 10){
        printf("\n%13d %17s %14d %14d %14d %14d %14d", rank, p->name, p->points, p->addPoints, p->subPoints, p->mulPoints, p->divPoints);
        p = p->next;
        rank++;
    }
    printf("\n%93s", "--------------------------------------------------------------------");

    printf("\n\n%45s", "");
    printf("==PRESS ENTER TO GO BACK===");
    _getch();
}

int question(int *opType){
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int op = rand() % 4;
    int user, correct;

    *opType = op;

    switch(op){
        case 0:
        printf("\n%56s", "");
        printf("%d + %d = ", a, b);
        correct = a + b;
        break;
        case 1:
            printf("\n%56s", "");
            printf("%d - %d = ", a, b);
            correct = a - b;
            break;
        case 2:
            printf("\n%56s", "");
            printf("%d x %d = ", a, b);
            correct = a * b;
            break;
        case 3:
            correct = a;
            int temp = a * b;
            printf("\n%56s", "");
            printf("%d / %d = ", temp, b);
    }

    if(scanf("%d", &user) != 1){
        while(getchar() != '\n');
        user = -999;
    }

    if(user == correct){
        printf("\n%58s", "");
        printf("CORRECT!");
        _getch();
        return 1;
    }
    else{
        printf("\n%56s", "");
        printf("WRONG ANSWER!");
        _getch();
        return 0;
    }
}

int scenario(int *r,  int *opType){
    int correct = 0, luck = 10, x, op[3], res[3], scenarioTotal = 0;



    for(int i = 0; i < 3; i++){
        res[i] = numberRoll(10);
        if(question(&op[i])){
            switch(op[i]){
                case 0:
                    currentUser->addPoints++;
                    break;
                case 1:
                    currentUser->subPoints++;
                    break;
                case 2:
                    currentUser->mulPoints++;
                    break;
                case 3:
                    currentUser->divPoints++;
                    break;
            }
            correct++;
        }
    }
    luck = 10 + (correct * 30);
    printf("\n%93s", "--------------------------------------------------------------------");
    printf("\n%57s", "");
    printf("LUCK = %d", luck);

    x = numberRoll(luck);
    *r = x;

    printf("\n\n%53s", "");
    printf("ROLLING NUMBER: ");
    sleep(3);
    printf("%d", x);

    _getch();
    return scoring(x);
}

int numberRoll(int luck){
    if(luck == 100){
        return 7;
    }
    else{
        int proba = rand() % 100 + 1;

        if(proba <= luck){
            return 7;
        }
        else{}
        return rand() % 9 + 1;
    }
}

int scoring(int x){
    switch(x){
    case 7:
        return 1000;
    case 6:
    case 8:
        return 800;
    case 5:
    case 9:
        return 600;
    case 4:
        return 500;
    case 3:
        return 400;
    case 2:
        return 300;
    case 1:
        return 200;
    }
    return 0;
}

void game(){
    system("cls");
    int scenario1, scenario2, scenario3, total = 0, opType;
    currentUser->addPoints = 0;
    currentUser->subPoints = 0;
    currentUser->mulPoints = 0;
    currentUser->divPoints = 0;


    srand(time(NULL));

    printf("%89s", "=====================START GAME====================\n\n");
    printf("\n%54s", "");
    printf("===SCENARIO 1===\n\n");
    scenario(&scenario1, &opType);
    system("cls");
    printf("%54s", "");
    printf("===SCENARIO 2===\n\n");
    scenario(&scenario2, &opType);
    system("cls");
    printf("%54s", "");
    printf("===SCENARIO 3===\n\n");
    scenario(&scenario3, &opType);

    printf("\n%93s", "--------------------------------------------------------------------");
    printf("\n\n%52s", "");
    printf("RESULTS: |%d| |%d| |%d|\n", scenario1, scenario2, scenario3);

    if(scenario1 == 7 && scenario2 == 7 && scenario3 == 7){
        total = 3000;
        printf("\n%69s", "===+JACKPOT+===");
    }
    else{
        total = scoring(scenario1) +scoring(scenario2) + scoring(scenario3);
    }

    printf("\n%52s", "");
    printf("TOTAL POINTS: %d", total);
    _getch();

    currentUser->points = total;
    sort();
    save();
    leaderboard();
}

void save(){
    FILE *fp;
    USER *p = head;

    fp = fopen("USERACC.txt", "w");

    if(fp == NULL){
        printf("ERROR FILE!\n\n");
        system("pause");
        return;
    }
    else{
        while(p != NULL){
            fprintf(fp, "%s,%d,%d,%d,%d,%d,%d\n", p->name, p->password, p->points, p->addPoints, p->subPoints, p->mulPoints, p->divPoints);
            p = p->next;
        }
        fclose(fp);
    }
}

void retrieve(){
    FILE *fp;
    char line[100];
    char name[50];
    int pass, pts, add, sub, mul, div;

    head = NULL;

    fp = fopen("USERACC.txt", "r");

    if(fp == NULL){
        return;
    }
    while(fgets(line, sizeof(line), fp)){
        sscanf(line, "%[^,],%d,%d,%d,%d,%d,%d", name, &pass, &pts, &add, &sub, &mul, &div);
        regi(name, pass, pts, add, sub, mul, div);

        USER *p = head;
        while(p != NULL){
        if(strcmp(p->name, name) == 0){
            p->addPoints = add;
            p->subPoints = sub;
            p->mulPoints = mul;
            p->divPoints = div;
        }
        p = p->next;
    }
    }
    fclose(fp);
}

void tempRemove(char n[]){
    USER *p = head, *q = NULL;

    while(p != NULL && strcmp(p->name, n) != 0){
        q = p;
        p = p->next;
    }

    if(p == NULL){
        return;
    }
    if(q == NULL){
        head = p->next;
    }
    else{
        q->next = p->next;
    }

    free(p);
}

void sort(){
    USER *i, *j;

    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(j->points > i->points){
                char name[50];
                int pass, pts, add, sub, mul, div;

                strcpy(name, i->name);
                pass = i->password;
                pts = i->points;
                add = i->addPoints;
                sub = i->subPoints;
                mul = i->mulPoints;
                div = i->divPoints;

                strcpy(i->name, j->name);
                i->password = j->password;
                i->points = j->points;
                i->addPoints = j->addPoints;
                i->subPoints = j->subPoints;
                i->mulPoints = j->mulPoints;
                i->divPoints = j->divPoints;

                strcpy(j->name, name);
                j->password = pass;
                j->points = pts;
                j->addPoints = add;
                j->subPoints = sub;
                j->mulPoints = mul;
                j->divPoints = div;
            }
        }
    }
}
