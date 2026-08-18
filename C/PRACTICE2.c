#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Ticket{
    int num[6];
}TICKET;

TICKET tickets[MAX];

int main(){
    srand(time(NULL));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            tickets[i].num[j] = rand() % 48 + 10;
        }
    }

    for(int i = 0; i <5; i++){
        printf("Ticket %d: ", i + 1);
        for(int j = 0; j < 6; j++){
            printf("%d", tickets[i].num[i]);
        }
        printf("\n");
    }
    return 0;
}
