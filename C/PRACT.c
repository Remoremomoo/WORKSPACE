//Array of Integers
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
//GLOBAL VARIABLES
int num[MAX];
int last = -1;
//array is initially empty
//UDFs declaration
void addRecord(int x);
void delRecord(int x);
void display();
int isfull();
int isempty();
int locate(int x);
int menu();
int main(){
    int x;
    while (1){
            //infinite loop
            switch(menu()){
                 case 1 :
                     printf("Input x: ");
                    scanf("%d",&x);
                    addRecord(x);
                    break;
                case 2 :
                    printf("Input x: ");
                    scanf("%d",&x);
                    delRecord(x);
                    break;
                case 3 :
                    display();
                    break;
                case 4 :
                    printf("Thank you for using this program.\n");
                    system("pause");
                    exit(0);
                default:
                    printf("1 to 4 lang! Shunga.\n");
                    system("pause");
                    }
                }
            return 0; } //UDF definitions

void addRecord(int x){
    if (isfull()){
            printf("Array is full!\n");
            system("pause");
        }
    else {
            last++;
    num[last] = x;
    printf("%d was added to the array.\n",x);
    system("pause");
    }
    }
void delRecord(int x){
    int p,i;
    if (isempty()){
            printf("Nothing to delete.\n");
    system("pause");
    }
    else {
            p = locate(x);
    if (p==-1){
            printf("Not found.\n");
    system("pause");
    }
    else {
            for (i=p;i<last;i++){
                num[i] = num[i+1];
    }
    last--;
    printf("%d was deleted from the array.\n",x);
    system("pause");
    }
    }
    }
    void display(){
        int i;
        system("cls");
        printf("The array contains:\n");
        for (i=0;i<=last;i++){
                printf("%d.) %d\n",i+1,num[i]);
        }
        system("pause");
        }
        int isfull(){
            return (last==MAX-1);
            }
            int isempty(){
                return (last == -1);
                //if (last==-1) return 1 else return 0;
                }
                int locate(int x){
                    for (int i=0;i<=last;i++)
                        if(num[i]==x)
                        return i;
                    return -1;//not found
                    }
int menu(){
    int ch;
    system("cls");
    printf("Menu\n");
    printf("1. Add Record\n");
    printf("2. Delete a Record\n");
    printf("3. Display All\n");
    printf("4. Exit\n");
    printf("Select[1-4]: ");
    scanf("%d",&ch);
    return ch;
}
