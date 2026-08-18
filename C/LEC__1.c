#include <stdio.h>
#include <stdlib.h>
#define MAX 2
//Local variables are defined inside the function and are not accessible to other functions within the program.

//User-defined functions
void getRecord(char n[] [50], int a[], int b[], int c[]); //Pass by reference
void display(char n[] [50], int a[], int b[], int c[]);
float avg(int a, int b, int c);

int main(){
    int q1[MAX], q2[MAX], q3[MAX], i;
    char name[MAX][50];
    getRecord(name, q1, q2, q3);
    display(name, q1, q2, q3);

    return 0;
}

void getRecord(){
    for(i = 0; i < MAX; ++i){
        printf("Input Name: ");
        scanf("%[^\n]", n[i]);
        printf("Input Quiz#1: ");
        scanf("%d", &a[i]);
        printf("Input Quiz#2: ");
        scanf("%d", &b[i]);
        printf("Input Quiz#3: ");
        scanf("%d", &c[i]);
        getchar();
    }
}
void display(){
    system("cls");
    float ave;
    printf("%4s %-20s %-6s %-6s %-6s %-8s %-10s\n", "No.", "Name", "Quiz1", "Quiz2", "Quiz3", "Average", "Remarks");
   for(i = 0; i < MAX; i++){
    ave = (float)(q1[i] + q2[i]+ q3[i]) / 3.0;
    printf("%4d.) %-20s %-6d %-6d %-6d %-8.2f %-10s\n", i+1, n[i], a[i], b[i], c[i], ave, ave >= 75.0? "PASSED" : "FAILED");
   }

}
float avg(int a, int b, int c){
    return a+b+c/3.0;

}

