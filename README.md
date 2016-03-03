# Assignment 3 - Justin LaPre
Comp Org assignment 3

DUE DATE: 11:59 p.m., Friday, March 11th, 2016.

## Assignment Description

For this  INDIVIDUAL assignment (no  groups allowed) you will  write a
2-D matrix  program similar to Assignment  1.  The twist  is this time
you must write your functions  in LLVM assembly language instead of C.
As we  saw in class during  Lecture 07, you  do *not* need to  use the
LLVM numbering  scheme for your  SSA instructions.  Instead,  use more
helpful variable names to aid you.

Again as in Assignment 1, we  will be using square matrices only.  You
must  write the  missing  functions  in LLVM  assembly.   You are  not
allowed to change any of the  function prototypes or modify any of the
code in the C file.

You must write the following functions:

- `void mm_print(int size, double **matrix)` -- print out the matrix
- `double **  mm_transpose(int size, double **matrix)`  -- compute and
  return           the           [transpose           of           the
  matrix](https://en.wikipedia.org/wiki/Transpose)
- `double   **mm_matrix_mult(int   size,   double   **matrix,   double
**transpose)`  --  compute  and  return  the  result  of  [multiplying
matrices](https://en.wikipedia.org/wiki/Matrix_multiplication)
`matrix` and `transpose`

**NOTE**: You  will likely need  to retrieve the  top 2 lines  of your
  `matrix.ll`  file by  generating `main.ll`  with the  command `clang
  -Wall -S  -emit-llvm main.c` and  taking the top two  lines starting
  with `target`.

## Grading Criteria

* Correctness: 85%
  - Print out the matrix correctly.
  - Computes matrix transpose correctly.
  - Computes matrix multiplication correctly.
* Documentation/Comments: 15% (i.e., liberal use of comments so we can
  understand your program).

Excuses  involving a  lack  of  understanding of  Github  will not  be
tolerated and  will result in a  20 point penalty in  addition to late
day  usage.  It  is a  simple enough  task to  check whether  you have
pushed your work to Github or not: in a web browser, go to your Github
user page  and find Assignment  3.  If it  says the last change  was X
minutes ago, you're probably all set.   If not, contact one of the TAs
immediately.  If  you still have  uncertainties about Github,  talk to
one of the TAs or an undergraduate mentor sooner rather than later.
