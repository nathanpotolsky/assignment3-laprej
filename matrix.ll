declare double** @mm_alloc(i32);

define double** @mm_transpose(i32 %size, double** %matrix) {
  %foo = call double** @mm_alloc(i32 %size);
  ret double** %matrix;
}

define double** @mm_matrix_mult(i32 %size, double** %matrix, double** %transpose) {
  ret double** %matrix;
}

define void @mm_print(i32 %size, double** %matrix) {
  ret void
}
