#include <stdio.h>
#include <stdlib.h>
#define MAX 2

int main(){
int q1[MAX], q2[MAX], q3[MAX], i;
float ave;
char name[MAX][50];

for(i = 0; i < MAX; ++i){
    printf("Input Name: ");
    scanf("%[^\n]", name[i]);
    printf("Input Quiz#1: ");
    scanf("%d", &q1[i]);
    printf("Input Quiz#2: ");
    scanf("%d", &q2[i]);
    printf("Input Quiz#3: ");
    scanf("%d", &q3[i]);
    getchar();

}
    system("cls");

    printf("%4s %-20s %-6s %-6s %-6s %-8s %-10s\n", "No.", "Name", "Quiz1", "Quiz2", "Quiz3", "Average", "Remarks");
   for(i = 0; i < MAX; i++){
    ave = (float)(q1[i] + q2[i]+ q3[i]) / 3.0;
    printf("%4d.) %-20s %-6d %-6d %-6d %-8.2f %-10s\n", i+1, name[i], q1[i], q2[i], q3[i], ave, ave >= 75.0? "PASSED" : "FAILED");
   }




 return 0;
}
