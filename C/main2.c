#include <stdio.h>
#include <stdbool.h>

int main()
{

    // variable = A reusable container for a value.
    //            Behaves as if it were the value it contains.

    int age = 25;
    int year = 2025;
    int quantity = 2;

    float gpa = 2.5;
    float price = 19.99;
    float temperature = -10.1;

    double pi = 3.14159265358979;
    double e = 2.7182818284590;

    char grade = 'F';
    char symbol = '!';
    char currency = '$';
    char name[] = "Godfrey Inigo";
    char food[] = "Pizza";
    char email[] = "fake123@gmail.com";
    
    bool isOnline = false;
    bool isStudent = true;
    bool forSale = false;

    printf("You are %d years old\n", age);
    printf("The year is %d\n", year);
    printf("You have ordered %d x items\n", quantity);

    printf("Your gpa is %.1f\n", gpa);
    printf("The price is $%.2f\n", price);
    printf("The temperature is %.1f°F\n", temperature);

    printf("The value of pi is %.14lf\n", pi);
    printf("The value of e is %.12lf\n", e);

    printf("Your grade is %c\n", grade);
    printf("Your favorite symbol is %c\n", symbol);
    printf("The currency is %c\n", currency);

    printf("Hello %s\n", name);
    printf("Your favorite food is %s\n", food);
    printf("Your email is %s\n", email);

    printf("%d\n", isOnline);

    if(isOnline){
        printf("You are ONLINE\n");
    }
    else{
        printf("You are OFFLINE\n");
    }

    if (isStudent)
    {
        printf("You are student\n");
    }
    else{
        printf("You are NOT a student\n");
    }
    
    if (forSale)
    {
        printf("That item is for sale");
    }
    else
    {
        printf("That item is NOT for sale");
    }
    

    return 0;
}