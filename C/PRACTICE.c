#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

typedef struct Record{
    char name[50];
    int id, grade;
}RECORD;

RECORD rec[MAX];
int val = -1;

int main(){
    RECORD x;
    int i, num;

    srand(time(NULL));

    while(val != MAX -  1){
        val++;
        system("cls");
        printf("ENTER NAME: ");
        scanf(" %[^\n]", x.name);
        printf("ENTER ID: ");
        scanf("%d", &x.id);
        getchar();
        num = rand() % 100 + 1;
        x.grade = num;
        rec[val] = x;
        printf("YOUR GRADE IS %d\n\n", x.grade);
        system("pause");
    }
    system("cls");
    printf("GRADE\n\n");
    for(i = 0; i <= val; i++){
        printf("%s | %d | %d\n", rec[i].name, rec[i].id, rec[i].grade);
    }
    return 0;

}
