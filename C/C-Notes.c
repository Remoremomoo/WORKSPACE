#include <stdio.h>
#include <string.h> // To access string functions.
#include <stdbool.h> // to access boolean functions.

int main(){

    /*
    These are the Variables and their variable types.
    Int for Integer or decimal, it's for positive and negative numbers.
    Float for Float or numbers with up to 8 decimal places.
    Double for Double or numbers with up to 16 decimal places.
    Bool for Boolean, it's a variable with 2 outputs, the False(0) or True(1).
    Char for Character or a variable with a single character, symbol, or letter.
    Char [], it's used to represent a string or a combination of characters, symbols, or letters with
             a number in the [] as the character limit.
    Const for a constant variable, or a variable that cannot be changed.
    Equals (=) is used as assignment operator, or assigning value to a variable.
    */
    int Integer = 20;
    float Float = 2.718;
    double Double = 3.14159269455;
    bool Boolean = true;
    char Character = '$';
    char String[20] = "I Am Groot";
    const int Constant = 21;


    /*
    Printf is used to print an output.
    Format specifiers are then used to print the value of the variable.
    */
    printf("This is a Printf output\n");    // \n is used to proceed to the next line.
    printf("This\tis\ta\tPrintf\toutput\n\n"); // \t is used to enter Tab in the output.
    printf("This is an Integer: %d\n", Integer);    // %d is used to print the value of an Int.
    printf("This is a Float: %f\n", Float);    // %f is used to print the value of a Float.
    printf("This is a Double: %lf\n", Double);    // %lf is used to print the value of a Double.
    printf("This is a Boolean: %d\n", Boolean);    // %d is also used to print the value of a Boolean.
    printf("This is a Character: %c\n", Character);    // %c is used to print the value of a Character.
    printf("This is a String: %s\n", String);    // %s is used to print the value of a String.
    printf("This is an Constant Integer: %d\n", Constant);

    printf("\n\nNext lesson\n\n");
    /*
    There are also more to format specifiers
    Width to adjust the space of the output.
    Precision to adjust the precision of decimal, useful for float and double.
    */
    int a = 1, b = 11, c = 111;
    printf("This is for the WIDTH\n");
    printf("This is with 5 spaces\n"); // Positive number is for Right Align.
    printf("%5d\n", a);                // The number indicates the number of spaces used by the output.
    printf("%5d\n", b);
    printf("%5d\n\n", c);

    printf("This is with -5 spaces\n"); // Negative number is for Left Align.
    printf("%-5d\n", a);                // The number indicates the number of spaces used by the output.
    printf("%-5d\n", b);
    printf("%-5d\n\n", c);

    printf("This is with 5 spaces and 0 as the space\n");
    printf("%05d\n", a);                // Zero is used to replace the spaces.
    printf("%05d\n", b);                // The number indicates the number of spaces used by the output.
    printf("%05d\n\n", c);

    float q = 1.1111, w = 2.2222;
    double e = 3.33333333, r = 4.44444444;
    printf("This is for the PRECISION\n");      // Dot followed by a number indicate the Decimal places.
    printf("This is for 2 decimal places: %.2f\n", q);              
    printf("This is for 4 decimal places: %.4f\n", w);
    printf("This is for 6 decimal places: %.6lf\n", e);
    printf("This is for 8 decimal places: %.8lf\n", r);

    printf("\n\nNext lesson\n\n");
    /*
    There are multiple Arithmetic Operations.
    + to Add
    - to Subtract
    * to Multiply
    / to Divide
    % to get the remainder
    */
    int num1 = 100, num2 = 20, result = 0;
    printf("Arithmetic Operations\n");
    result = num1 + num2;
    printf("Addition: %d + %d = %d\n", num1, num2, result);

    result = num1 - num2;
    printf("Subtraction: %d - %d = %d\n", num1, num2, result);
    
    result = num1 * num2;
    printf("Multiplication: %d * %d = %d\n", num1, num2, result);
    
    result = num1 / num2;
    printf("Division: %d / %d = %d\n", num1, num2, result);
    
    result = num1 % 3;
    printf("Modulus/Remainder: %d / 3 = %d\n", num2, result);

    printf("\n\nNext lesson\n\n");
    /*
    ++ Increment by 1
    -- Decrement by 1
    += Used to increase the value of a variable by a certain number.
    -= Used to decrease the value of a variable by a certain number.
    *= Used to multiply the value of a variable by a certain number.
    /= Used to divide the value of a variable by a certain number.
    */
    int inc = 0, dec = 5, AMul = 2, ADiv = 30;
    printf("This is Augmented Assignment Operators\n");
    printf("Augmented Addition\n"); // Increasing the value of the same variable by 1.
    printf("%d\n", inc);
    inc += 1;
    printf("%d\n", inc);
    inc += 1;
    printf("%d\n", inc);
    inc += 1;
    printf("%d\n", inc);
    inc += 1;
    printf("%d\n", inc);
    inc += 1;
    printf("%d\n\n", inc);

    printf("Augmented Subtraction\n"); // Decreasing the value of the same variable by 1.
    printf("%d\n", dec);
    dec -= 1;
    printf("%d\n", dec);
    dec -= 1;
    printf("%d\n", dec);
    dec -= 1;
    printf("%d\n", dec);
    dec -= 1;
    printf("%d\n", dec);
    dec -= 1;
    printf("%d\n\n", dec);

    printf("Augmented Multiplication\n"); // Multiplying the value of the same variable by 4.
    printf("%d\n", AMul);
    AMul *= 4;
    printf("%d\n", AMul);
    AMul *= 4;
    printf("%d\n\n", AMul);

    printf("Augmented Division\n"); // Dividing the value of the same variable by 3.
    printf("%d\n", ADiv);
    ADiv /= 3;
    printf("%d\n", ADiv);
    ADiv /= 3;
    printf("%d\n\n", ADiv);

    printf("\n\nNext lesson\n\n");
    /*
    Scanf and Fgets function
    It is used to get an Input from the user.
    Scanf is commonly used for Numbers.
    Fgets is recommended for inputting strings.
    */
    int Int = 20;
    float Flt = 2.718;
    double Dble = 3.14159269455;
    char Chr = '$';
    char Strg[20] = "I Am Groot";

    printf("Inputs\n");
    printf("Enter an Integer: ");
    scanf("%d", &Int);
    printf("Enter a Float: ");
    scanf("%f", &Flt);
    getchar();
    printf("Enter a Double: ");
    scanf("%lf", &Dble);
    printf("Enter a Char: ");
    scanf(" %c", &Chr);
    getchar();
    printf("Enter a String: ");
    fgets(Strg, sizeof(Strg), stdin);
    Strg[strlen(Strg)-1] = '\0';

    printf("\nOutput\n");
    printf("Print Integer = %d\n", Int);
    printf("Print Float = %.2f\n", Flt);
    printf("Print Double = %.8lf\n", Dble);
    printf("Print Character = %c\n", Chr);
    printf("Print String = %s\n", Strg);

    /*
    Final notes:
    getchar(); - is a function to remove buffer or extra space in the code that might
                 lead to skipping other lines of code.

    VARIABLE[strlen(VARIABLE)-1] = '\0'; - is function used to remove the buffer or
                                           extra space in the code that might lead
                                           to skipping other lines of code.
    
    & - it is used to address the input into the variable, basically assigning its
        value to the variable.                                       
    */
    return 0;
}