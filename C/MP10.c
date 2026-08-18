#include <stdio.h>
#include <stdlib.h>

int factorial(int x);
void rev(int x);
int pal(int x);
int strl(char *str);
int sum(int arr[], int x);


int main(){
    int choice = 0;

    while(1){
        system("cls");
        printf("MENU\n\n");
        printf("1. FACTORIAL\n2. REVERSE DIGITS\n3. PALINDROME\n4. STRING LENGTH\n5. ARRAY SUM\n6. EXIT\n\n");
        printf("CHOOSE [1-5]: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
        case 1:{
                int n, x;
                system("cls");
                printf("INPUT A NUMBER: ");
                scanf("%d", &n);

                x = factorial(n);
                printf("\n\nFACTORIAL OF %d IS %d.\n", n, x);
                system("pause");
                break;
        }
        case 2:{
            int m, y;
                system("cls");
                printf("INPUT CONSECUTIVE NUMBERS: ");
                scanf("%d", &m);

                printf("\n\nREVERSE OF %d IS ", m);
                rev(m);
                printf(".\n");
                system("pause");
                break;
        }
        case 3:{
                int o, z;
                system("cls");
                printf("INPUT 4-DIGIT NUMBER: ");
                scanf("%d", &o);
                z = pal(o);
                if(z  > -1){
                    printf("\n\nTHE NUMBER ""%d"" IS A PALINDROME\n\n", o);
                    system("pause");
                }
                else{
                    printf("\n\nTHE NUMBER ""%d"" IS NOT A PALINDROME\n\n", o);
                    system("pause");
                }
                break;
        }
        case 4:{
                char s[50];
                system("cls");
                printf("INPUT A STRING: ");
               scanf(" %[^\n]", s);

                printf("\n\nTHE LENGTH OF %s IS %d.\n\n", s, strl(s));
                system("pause");

                break;
        }
        case 5:{
                int v, i, total;
                system("cls");

                printf("ENTER SIZE OF ARRAY: ");
                scanf("%d", &v);

                int array[v - 1];

                printf("\n\nENTER %d VALUES: ", v);
                for(i = 0; i <= v - 1; i++){
                    scanf("%d", &array[i]);
                }
                total = sum(array, v);

                printf("\n\nTHE SUM OF ARRAY VALUES IS %d\n\n", total);
                system("pause");
                break;
        }
        case 6:
            printf("\n\nTHANK YOU!\n\n");
            exit(0);
            break;
        default:
            printf("\n\nINVALID CHOICE!\n\n");
            system("pause");
            break;
        }
    }
}

int factorial(int x){
    if(x == 1){
        return x;
    }
    else{
        return x * factorial(x - 1);
    }
}

void rev(int x){
        if(x < 10){
            printf("%d", x);
            return;
        }
        else{
            printf("%d", x % 10);
            return rev(x / 10);
        }
    }

int pal(int x){
        int a, b;
             if(x < 10){
                return 0;
             }
             else{
                if(x >= 1000){
                    a = x / 1000;
                    b = x % 10;

                    if(a == b){

                       x = (x % 1000) / 10;

                        return pal(x);
                    }
                    else{
                        return -1;
                    }
                }
                else{
                    a = x / 10;
                    b = x % 10;

                    if(a == b){
                        x = 0;

                        return pal(x);
                    }
                    else{
                        return -1;
                    }
                }
        }
    }

int strl(char *str){
    if(*str == '\0'){
        return 0;
    }
    else{
        return 1 + strl(str + 1);
    }
}

int sum(int arr[], int x){
    if(x == 0){
        return 0;
    }
    else{
        return arr[0] + sum(arr + 1, x - 1);
    }
}
