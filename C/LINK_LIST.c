#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Node{
    char name[50];
    int age;
    struct Node* next;
}NODE;

NODE *head;

void initialize();
void addData(char n[], int x);
void delData(char n[]);
void display();

int main(){
    initialize();

    addData("Mel chor", 10);
    addData("Gas Par", 15);
    addData("Hud as", 20);

    display();

    delData("Ar Te");
    delData("Gas Par");
    display();

    return 0;
}

void initialize(){
    head = NULL;
}

void addData(char n[], int x){
    NODE *newNode, *p, *q;
    p = q = head;
    newNode = (NODE*) malloc(sizeof(NODE));
    strcpy(newNode->name, n);
    newNode->age = x;

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

void delData(char n[]){
    NODE *p, *q;
    p = q = head;
    while(p != NULL && strcmp(n, p->name) != 0){
        q = p;
        p = p->next;
    }

    if(p == NULL){
        printf("\n\n%s not found!\n\n", n);
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

void display(){
    NODE *p = head;
    int i=1;
    printf("NAME      AGE      REMARKS\n");
    while (p!=NULL){
        printf("%d.) %s      %d      %s\n",i++,p->name,p->age,(p->age>=18)?"Adult":"Minor");
        p=p->next;
    }
}


