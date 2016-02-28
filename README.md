# Assignment 3
Comp Org assignment 3

DUE DATE: 11:59 p.m., Friday, March 11th, 2016.

## Assignment Description

For this INDIVIDUAL assignment (no groups allowed) you will write a 2-D matrix program similar to Assignment 1.
The twist is this time you must write your functions in LLVM assembly language instead of C.
As we saw in class during Lecture 07, you do *not* need to use the LLVM numbering scheme for your SSA instructions.
Instead, use more helpful variable names to aid you.

Again as in Assignment 1, we will be using square matrices only.
You must write the missing functions in LLVM assembly.
You are not allowed to change any of the function prototypes or modify any of the code in the C file.

You must write the following functions:
- `void mm_print(int size, double **matrix)` -- print out the matrix
- `double ** mm_transpose(int size, double **matrix)` -- compute and return the [transpose of the matrix](https://en.wikipedia.org/wiki/Transpose)
- `double **mm_matrix_mult(int size, double **matrix, double **transpose)` -- compute and return the result of multiplying matrices `matrix` and `transpose`

## Grading Criteria

* Correctness: 85%
  - allocates and frees memory correctly.
  - Computes matrix swap correctly.
  - Computes matrix multiplication correctly.
  - Checks for return values on all functions.
* Documentation/Comments: 15% (i.e., liberal use of comments so we can understand your program).
