# Number Checker

## Overview
This is a simple C utility program designed to check whether a user-provided integer is **Even** or **Odd**.

## How it Works
1. The program prompts the user to enter a single integer.
2. It reads the input and validates that it is a valid integer. If the input is invalid (e.g., characters instead of numbers), it outputs an error message and exits safely.
3. The core logic relies on a boolean function called `isEven()`, which checks if the number is perfectly divisible by 2 using the modulo operator (`users_num % 2 == 0`).
4. Depending on the result of `isEven()`, it prints whether the entered number is even or odd.

## Usage
Compile the source code using a C compiler and run the executable. Enter a whole number when prompted to see if it is even or odd.
