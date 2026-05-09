# Cramer's Rule Solver

## Overview
This is a simple C program that solves a system of two linear equations with two variables using **Cramer's Rule**. 

The system of equations is represented as:
1. `ax + by = e`
2. `cx + dy = f`

## How it Works
The program prompts the user to input the coefficients for both equations:
- First, the coefficients `a`, `b`, and the constant `e` for the first equation.
- Then, the coefficients `c`, `d`, and the constant `f` for the second equation.

It then calculates the determinant of the main coefficient matrix (`D = (a * d) - (b * c)`).
- If the main determinant `D` is equal to `0`, the system does not have a unique solution, and the program will output an error message.
- If `D` is non-zero, it proceeds to calculate the determinants for `x` (`Dx`) and `y` (`Dy`), and determines their values by dividing by the main determinant (`x = Dx / D` and `y = Dy / D`).

Finally, it prints the calculated values of `x` and `y`.

## Usage
Compile the code using a standard C compiler (e.g., GCC) and run the executable. Follow the on-screen prompts to enter the coefficients separated by commas.
