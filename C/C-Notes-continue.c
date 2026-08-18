#include <stdio.h> // To access standard input and output.
#include <string.h> // To access string variable and function.
#include <stdbool.h> // To access boolean variable and function.
#include <stdlib.h> // To access random number generator function.
#include <math.h> // To access more math functions.
#include <windows.h> // To access Sleep() function.
#include <time.h> // To access time function for random number generator.

void VoidFunctionName(); // Function Declaration or Prototype is done before the main function.

void IfStatement(int IfNum1, int IfNum2){
    /*
    If Statement is used to run a sequence of condition until one is satisfied.
    If - start with the function IF to check if the first condition is executable.
    Else If - it follows the previous IF function. It runs if the first condition wasn't satisfied.
    Else - this runs if all the previous conditions are not satisfied.
    */
    if (IfNum1 > IfNum2){
        printf("%d is GREATER than %d\n", IfNum1, IfNum2);
    }
    else if (IfNum2 > IfNum1){
        printf("%d is GREATER than %d\n", IfNum2, IfNum1);
    }
    else{
        printf("%d and %d are EQUAL\n", IfNum1, IfNum2);
    }
}


void SwitchLoop(char oper, int ans, int input){
    /*
    Switch Case Function is used to run a sequence of condition based on the value of a variable.
    Switch - start with the function SWITCH to check the value of the variable.
    Case - it follows the previous SWITCH function. It runs if the value of the variable matches the case value.
    Break - it is used to exit the switch case function after a case is executed.
    Default - this runs if all the previous cases are not satisfied.
    */
    switch(oper){
        case '+':
            printf("%d %c %d = %d\n", ans, oper, input, ans+input);
            break;
        case '-':
            printf("%d %c %d = %d\n", ans, oper, input, ans-input);
            break;
        case '*':
            printf("%d %c %d = %d\n", ans, oper, input, ans*input);
            break;
        case '/':
            printf("%d %c %d = %d\n", ans, oper, input, ans/input);
            break;
        default:
            printf("Syntax Error\n");
    }

}


void WhileLoop1(int counter){
    /*
    While Loop Function is used to run a sequence of code while a condition is true.
    Do While Loop - it runs the code at least once before checking the condition.
    While Loop - it checks the condition before running the code.
    Sleep() - it is used to pause the code for a certain amount of time in milliseconds.
    1000 milliseconds = 1 second
    */
    int separate;
    separate = counter;
    printf("Countdown ");
    do{
        printf("...%d ", counter);
        counter--;
        Sleep(1000);
    }while (counter >= 0);
}
void WhileLoop2(int counter){
    while (counter > 0){
        printf("\nSKIBIDI");
        counter--;
        Sleep(500);
    }
}   


void ForLoop(char symb, int rows, int column){
    /*
    For Loop Function is used to run a sequence of code for a certain number of times.
    For Loop - it runs the code for a certain number of times based on the condition.
    1st part - it initializes the variable.
    2nd part - it checks the condition.
    3rd part - it increments or decrements the variable.
    */
    for (int i = 0; i < rows; i++){ // int i = 0 is the initialization, i < rows is the condition, i++ is the increment.
        for (int j = 0; j < column; j++){
            printf("%c", symb);
        }
        printf("\n");
    }
}


void RandomNum(){
    /*
    Random Number Function is used to generate a random number between a certain range.
    rand() - it generates a random number.
    srand(time(0)) - it seeds the random number generator with the current time.
    % - it is used to get the remainder of a division.
    100 + 1 - it is used to set the range of the random number between 1 to 100.
    */
    int Guessnum, Answer, Tries = 0;
    srand(time(0)); // Seed the random number generator with the current time
    Answer = rand() % 100 + 1; // Generate a random number between 1 and 100
    printf("Guess a number between 1 to 100\n");
    do{
        printf("Enter your guess: ");
        scanf("%d", &Guessnum);
        Tries++;
        if (Guessnum > Answer){
            printf("Too High!\n");
        }
        else if (Guessnum < Answer){
            printf("Too Low!\n");
        }
        else{
            printf("You guessed it in %d tries!\n", Tries);
        }
    }while (Guessnum != Answer);
}


int main(){
    /*
    In Math.h library, there are multiple advanced math operators that can be used.
    sqrt() - used to sqare root a number
    pow(x,degree) - used to solve for exponent
    round() - used to round off the number
    ceil() - used to round up the number
    floor() - used to round down the number
    abs() - used to solve for the absolute value of the number
    log () - used to find the logarithm of the number
    sin() cos() tan() - used to solve for the sine cosine tangent
    */
    float square = 0.0f;
    int degree = 0;
    int inte = 0;
    char Sentence[50] = "";

    printf("Enter a number to square root: ");
    scanf("%f", &square);
    printf("Square root of %.2f = %.3f\n", square, sqrt(square));

    printf("\nEnter a number: ");
    scanf("%f", &square);
    printf("Enter its exponent: ");
    scanf("%d", &degree);
    printf("%.2f raised to %d = %.3f\n", square, degree, pow(square, degree));

    printf("\nEnter a number to round off: ");
    scanf("%f", &square);
    printf("%.2f rounded off = %.3f\n", square, round(square));
    printf("%.2f rounded up = %.3f\n", square, ceil(square));
    printf("%.2f rounded down = %.3f\n", square, floor(square));

    printf("\nEnter a number to get the absolute value of: ");
    scanf("%d", &inte);
    printf("Absolute value of %d = %d\n", inte, abs(inte));

    printf("\nEnter a number to get the Logarithm: ");
    scanf("%f", &square);
    printf("Logarithm of %.2f = %.3f\n", square, log(square));
    
    printf("\nEnter an Angle/Degree: ");
    scanf("%d", &inte);
    printf("Sine of %d degrees = %.3f\n", inte, sin(inte));
    printf("Cosine of %d degrees = %.3f\n", inte, cos(inte));
    printf("Tangent of %d degrees = %.3f\n", inte, tan(inte));


    printf("\n\nNext lesson\n");
    printf("Void Function Lesson\n");
    // We called the function and pass the argument.
    VoidFunctionName();


    printf("\n\nNext lesson\n");
    printf("If Function Lesson\n");
    int IfNum1, IfNum2;
    printf("Enter the first number: ");
    scanf("%d", &IfNum1);
    printf("Enter the second number: ");
    scanf("%d", &IfNum2);
    IfStatement(IfNum1, IfNum2);
  

    printf("\n\nNext lesson\n");
    printf("Switch Case Lesson\n");
    int ans, input;
    char oper;
    printf("Enter first number: ");
    scanf("%d", &ans);
    printf("Enter second number: ");
    scanf("%d", &input);
    printf("Pick an operator (+-*/): ");
    scanf(" %c", &oper);
    SwitchLoop(oper, ans, input);


    printf("\n\nNext lesson\n");
    printf("Do while Loop Lesson\n");
    int loop;
    printf("Enter a number that will count down: ");
    scanf("%d", &loop);
    WhileLoop1(loop);
    WhileLoop2(loop);


    printf("\n\nNext lesson\n");
    printf("For Loop Lesson\n");
    int rows, column;
    char symb;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of column: ");
    scanf("%d", &column);
    printf("Pick a symbol: ");
    scanf(" %c", &symb);
    ForLoop(symb, rows, column);

    printf("\n\nNext lesson\n");
    printf("Random Number Generator Lesson\n");
    RandomNum();
    return 0;
}

void VoidFunctionName(){ // Function Definition - it is done after the main function.
    /*
    Function is used to run a sequence of code when called.
    Void - it is used when the function does not return a value.
    Function Call - it is done inside the main function to run the function.
    Argument - it is the value passed to the function when called.
    Parameter - it is the variable that receives the value passed to the function.
    */
   char Sentence[50] = "";
    printf("This is a Function\n");
    printf("This function does not return a value\n");
    printf("This function does not have an argument or parameter\n");
    getchar();
    printf("\nEnter your name: ");
    fgets(Sentence, sizeof(Sentence), stdin);
    Sentence[strlen(Sentence)-1] = '\0';
    printf("Hello my name is %s\n", Sentence);
}