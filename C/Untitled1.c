#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;

    printf("ENTER VALUE: ");
    scanf("%d", &x);

    while(x != 1){
        if(x % 2 == 0){
            x = x / 2;
        }
        else{
            x = (x * 3) + 1;
        }
    }
    printf("\n\nSTOP! %d\n\n", x);
    system("pause");

    return 0;
}
