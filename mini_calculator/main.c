#include <stdio.h>
double addNum(double num1, double num2);
double subNum(double num1, double num2);
double mulNum(double num1, double num2);
double divNum(double num1, double num2);

int main(){
    char operation;
    double num1, num2;

    printf("Welcome what operation would you like to perform\n For addition input A\n For subtraction input S\n For division input D\n");
    printf("What is your desired operation?: ");
    scanf("%c", &operation);

    printf("Enter two numbers: \n");
    printf("Enter the first number: " );
    scanf("%lf", &num1);

    printf("\nEnter the second number: " );
    scanf("%lf", &num2);

    switch(operation){
        case 'A':
        case 'a':
            //call the add function
            printf("The sum of the two numbers: %.2f\n", addNum(num1, num2));
            break;

        case 'S':
        case 's':
            //run the subtraction function
            printf("The difference: %2f\n", subNum(num1, num2));
            break;

        case 'D':
        case 'd':
            //run the division function
            if(num2 != 0)
                printf("The quotient: %2f\n", divNum(num1, num2));
            else
                printf("Error: Division by Zero.\n");

            break;
        case 'M':
        case 'm':
            printf("The product: %.2f\n", mulNum(num1, num2));
            break;
        default:
            //default error message
            printf("Error ");
    }
    return 0;

}




//Calculation functions
double addNum(double num1, double num2){
    return num1 + num2;
}

//
double subNum(double num1, double num2){
    return num2 - num1;
}

//division function
double divNum(double num1, double num2){
    return num1 / num2;
}
//multiply function
double mulNum(double num1, double num2){
    return num1 * num2;
}


