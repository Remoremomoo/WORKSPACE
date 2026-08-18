#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int num[MAX];
int last = -1;
void addRecord();
void delRecord();
void display();
int locate(int x);
int isfull();
int isempty();
int menu();

int main(){
    int x;
    while(1){
        switch(menu()){
        case 1:
            printf("Enter value of x: ");
            scanf("%d", &x);
            addRecord(x);
            break;
        case 2:
            printf("Enter value of x to delete: ");
            scanf("%d", &x);
            delRecord(x);
            break;
        case 3:
            display();
            system("pause");
            break;
        case 4:
            printf("Thank you for using the program!\n");
            system("pause");
            break;
        default:
            printf("INVALID OPTION!");
            system("pause");
        }
    }
    return 0;

}

void addRecord(int x){
    if(isfull()){
        printf("\n\nARRAY IS FULL!");
        system("pause");
    }
    else{
        last++;
        num[last] = x;
        system("pause");
    }
}
void delRecord(int x){
    int p, i;
    if(isempty()){
        printf("\n\nARRAY IS EMPTY!");
        system("pause");
    }
    else{
        p = locate(x);
        if(p == -1){
            printf("\n\nVALUE DOES NOT EXIST!");
            system("pause");
        }
        else{
            for(i = p; i < last; i++){}
            num[i] = num[i + 1];
        }
        last--;
        printf("\n\n%d was deleted from the array.");
        system("pause");
    }
}
void display(){
    int i;
    system("cls");
    printf("The array contains:\n");
    for(i = 0; i <= last; i++){
        printf("%d.) %d\n", i + 1, num[i]);
    }
    system("pause");
}
int isfull(){
    return (last == MAX-1);
}
int isempty(){
    return (last == -1);
}
int locate(int x){
    int i;
    for(i = 0; i <= last; i++){
        if(num[i] == x){
            return i;
            return -1;
        }
    }
}
int menu(){
    int ch;
    system("cls");
    printf("MENU\n");
    printf("1. Add a Record\n2. Delete a Record\n3. Display All Record\n4. Exit");
    printf("\n\nChoose: ");
    scanf("%d", &ch);
    return ch;
}
