#include <stdio.h>
#include <stdbool.h>

bool solve_system(double a, double b, double c, double d, double e, double f, double *x, double *y);

int main(void){
    double a, b, c, d, e, f;
    double x, y;

    printf("Solve a system of equations:\n");
    printf("1: ax + by = e\n2: cx + dy = f\n");

    printf("Enter coefficient of a, b, e for equation 1: ");

    if(scanf("%lf, %lf, %lf", &a, &b, &e ) != 3){
        printf("Error: You're not to enter values less than or above 3.\n Also make sure your values are comma seperated. ");
        return 1;
    }

    printf("Enter coefficient (c, d, f) for equation 2: ");
    if(scanf("%lf, %lf, %lf", &c, &d, &f) != 3) return 1;

    if(solve_system(a,b, c, d, e, f, &x, &y)){
        printf("Solution found:\n");
        printf("x = %.2fl\n", x);
        printf("y = %.2f\n", y);
    } else{
        printf("\nError: The system has no unique solution (Determinant is 0.\n");
    }
}




//Function to calculate the equation and return true if it's calculations went through
bool solve_system(double a, double b, double c, double d, double e, double f, double *x, double *y) {

    //I calculate the main determinant
    double D = (a * d) - (b * c);

    //check if determinants is less than zero, just return error

    if (D == 0) {
        return false;
    }

    double Dx = (e * d) - (b * f);
    double Dy = (a * f) - (e * c);


    *x = Dx / D;
    *y = Dy / D;

    return true;

}
