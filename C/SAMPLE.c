#include <stdio.h>

void reverseDigits(int n){
    if(n < 10){        // base case
        printf("%d", n);
        return;
    }
    printf("%d", n % 10);   // print last digit
    reverseDigits(n / 10);  // recurse remaining digits
}

int main(){
    int num = 1234;
    printf("Original: %d\n", num);
    printf("Reversed: ");
    reverseDigits(num);
    printf("\n");
    return 0;
}
