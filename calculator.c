#include <stdio.h>

int main() {
    char operator;
    double num1, num2;
    int intNum1, intNum2;

    printf("Simple Calculator in C\n");
    printf("----------------------\n");

    // Taking operator input
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);

    // For modulus, use integer input
    if (operator == '%') {
        printf("Enter two integers: ");
        scanf("%d %d", &intNum1, &intNum2);

        if (intNum2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
        } else {
            printf("Result: %d %% %d = %d\n", intNum1, intNum2, intNum1 % intNum2);
        }
    } else {
        // For other operations, use double input
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch (operator) {
            case '+':
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                }
                break;
            default:
                printf("Invalid operator! Please use +, -, *, /, or %%.\n");
        }
    }

    return 0;
}
