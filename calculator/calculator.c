#include <stdio.h>

int main(void)
{
    int number1;
    char operator;
    int number2;
    int result;
    // Input for the first number
    printf("First number: ");
    scanf("%d", &number1);
    // Input for the operator until its a valid one
    while ((operator != '+') && (operator != '-') && (operator != '*') && (operator != '/'))
    {
        printf("Operator (accepted '+', '-', '*' and '/'): ");
        scanf(" %c", &operator);
    }
    // Input for the second number
    printf("Second number: ");
    scanf("%d", &number2);
    // Addition
    if (operator == '+')
    {
        result = number1 + number2;
        printf("%i %c %i = %i", number1, operator, number2, result);
    }
    // Substraction
    else if (operator == '-')
    {
        result = number1 - number2;
        printf("%i %c %i = %i", number1, operator, number2, result);
    }
    // Multiplication
    else if (operator == '*')
    {
        result = number1 * number2;
        printf("%i %c %i = %i", number1, operator, number2, result);
    }
    // Division
    else
    {
        result = number1 / number2;
        printf("%i %c %i = %i", number1, operator, number2, result);
    }
}
