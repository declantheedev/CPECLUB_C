# Mini Calculator

## Overview
This is a basic command-line calculator program written in C. It allows users to perform fundamental arithmetic operations: addition, subtraction, multiplication, and division on two numbers.

## How it Works
The program operates by asking the user to:
1. **Choose an operation**: 
   - `A` or `a` for Addition
   - `S` or `s` for Subtraction
   - `M` or `m` for Multiplication
   - `D` or `d` for Division
2. **Enter two numbers**: The user inputs the two operands they want to calculate.

A `switch` statement handles the selected operation and passes the numbers to specific mathematical functions (`addNum`, `subNum`, `mulNum`, `divNum`). 

It also features basic error handling, including a check for **division by zero** when the division operation is selected.

## Usage
Compile and run the program. Follow the prompt to enter the operation character, and then provide the two numbers when asked. The result will be printed to the console.
