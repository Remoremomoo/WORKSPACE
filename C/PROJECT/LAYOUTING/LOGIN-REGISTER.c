#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct User{
    char name[50];
    int password, points;
    struct User* next;
}USER;

USER *head;

void initialize();
void login(char n[], int x);
void regi(char n[], int x);

int main(){

    while(1){
        int flag = 0;
        int choice = 0, pass;
        char nm[50];

        printf("MENU\n\n");
        printf("1. REGISTER\n2. LOGIN\n\n");
        printf("CHOOSE: ");
        scanf("%d", &choice);
        getchar();
        USER *p = head;
        switch(choice){
        case 1:
            printf("\n\nENTER USERNAME: ");
            scanf(" %[^\n]", nm);
            while(p != NULL){
                if(strcmp(nm, p->name) == 0){
                    flag = 1;
                    break;
                }
                p = p->next;
            }
            if(flag){
                printf("\n\nUSERNAME ALREADY EXISTED!\n\n");
                system("pause");
                break;
            }
            printf("\nENTER PASSWORD: ");
            scanf("%d", &pass);
            regi(nm, pass);
            break;
        case 2:
            printf("\n\naENTER USERNAME: ");
            scanf(" %[^\n]", nm);
            printf("\nENTER PASSWORD: ");
            scanf("%d", &pass);

            login(nm, pass);
            break;
        }
    }
    return 0;
}

void initialize(){
    head = NULL;
}

void regi(char n[], int x){
    USER *p, *q, *newNode;
    p = q = head;
    newNode = (USER*) malloc(sizeof(USER));
    strcpy(newNode->name, n);
    newNode->password = x;
    newNode->points = 0;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
    if(newNode->points > head->points){
        newNode->next = head;
        head = newNode;
        return;
    }

    while(p != NULL && p->next->points >= newNode->points){
        q = p;
        p = p->next;
    }
    newNode->next = p;
    q->next = newNode;
}

void login(char n[], int x){
    USER *p, *q;
    p = q = head;

    while(p != NULL && strcmp(n, p->name) != 0 && x != p->password){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        printf("\n\nTHIS ACCOUNT DOES NOT EXIST!\n\n");
        printf("Try again...");
        getchar();
    }
    else{
        printf("LOG-IN SUCCESSFUL!\n\n");
        printf("ENTER TO CONTINUE...");
        getchar();
    }
}
