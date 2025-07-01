#include <stdio.h>

void add_one(int input) {
  input += 1;
}

void add_one_pointer(int* input) {
  *input += 1;
}

void add_one_double_ptr(int** input) {
  **input += 1;
}

int main() {
  int x = 5;

  add_one(x);
  printf("After add_one: %d\n", x);

  add_one_pointer(&x);
  printf("After add_one_pointer: %d\n", x);

  int* ptr = &x;
  add_one_double_ptr(&ptr);
  printf("After add_one_double_ptr: %d\n", x);

  return 0;
}
