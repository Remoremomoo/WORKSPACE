#include <stdio.h>

int main(){
    int x = 20, y = 30;
    int *ptr, *ptr2;
    ptr = &x;
    ptr2 = &y;

    printf("%d\n", x);
    printf("%d\n", &x);
    printf("%d\n", ptr);
    printf("%d\n", y);
    printf("%d\n", *ptr2);
    printf("%d\n", &ptr);
    printf("%d\n", &ptr2);

    return 0;
}
