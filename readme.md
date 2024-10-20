# Matrix Operations in C++

This project demonstrates dynamic memory allocation and manipulation of matrices of user-defined sizes in C++. It provides functions to perform the following operations on matrices:
- Addition
- Subtraction
- Multiplication
- Transpose

## Getting Started

### Prerequisites
You will need a C++ compiler to run this project. For example, you can use:
- GCC (GNU Compiler Collection)
- Visual Studio C++ Compiler

Make sure that your system is set up to compile and run C++ code.

### Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/matrix-operations.git
    ```

2. Navigate into the project directory:
    ```bash
    cd matrix-operations
    ```

3. Compile the project:
    ```bash
    g++ matrix_operations.cpp -o matrix_operations
    ```

4. Run the program:
    ```bash
    ./matrix_operations
    ```

## How It Works

### User Input
The program first prompts the user to enter the dimensions (number of rows and columns) for two matrices. Then, the user is asked to input the elements for each matrix.

### Supported Operations
Once the matrices are defined, the program performs the following operations:
1. **Addition**: Adds corresponding elements of two matrices.
2. **Subtraction**: Subtracts the second matrix from the first.
3. **Multiplication**: Multiplies the two matrices if their dimensions are compatible.
4. **Transpose**: Swaps the rows and columns of both matrices.

Each operation is implemented as a separate function.

## Features

- **Dynamic memory allocation**: Matrices are created using dynamic memory allocation, ensuring the program can handle matrices of varying sizes.
- **Separate functions**: Each operation (addition, subtraction, multiplication, transpose) is encapsulated in a separate function for clean code structure.
- **Matrix input and output**: Functions are provided to input and output the matrices, ensuring easy interaction with the user.

## Functions Description

### `calculate_addition()`
```cpp
void calculate_addition(int rows1, int columns1, int rows2, int columns2, int **ptr1, int **ptr2);
void calculate_subtraction(int rows1, int columns1, int rows2, int columns2, int **ptr1, int **ptr2);
void calculate_multiplication(int rows1, int columns1, int rows2, int columns2, int **ptr1, int **ptr2);
void calculate_transpose(int rows1, int columns1, int rows2, int columns2, int **ptr1, int **ptr2);
Enter number of rows of matrix 1: 2
Enter number of columns 1: 2
Enter array elements 1: 
1 2
3 4

Enter number of rows of matrix 2: 2
Enter number of columns 2: 2
Enter array elements 2: 
5 6
7 8

Addition of Matrices 1 & 2 is: 
6 8 
10 12 

Subtraction of Matrices 1 & 2 is: 
-4 -4 
-4 -4 

Multiplication of Matrices 1 & 2 is: 
19 22 
43 50 

Transpose matrix 1 is:
1 3 
2 4 

Transpose matrix 2 is:
5 7 
6 8


