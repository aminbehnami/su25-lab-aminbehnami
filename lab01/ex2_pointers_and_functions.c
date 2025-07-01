#include <stdio.h>

void add_one(int input) {
  input += 1;
}

// TODO: create a pointer to input
void add_one_pointer(int* input) {
  // TODO: add one to the integer that input points to
  *input += 1;
}

// TODO: create a pointer to a pointer to input
void add_one_double_ptr(int** input) {
  // TODO: add one to the integer that input doubly points to
  **input += 1;
}

int main() {
  // Assign x (an integer) to 5
  int x = 5;

  // Call add_one with x
  add_one(x);
  printf("After add_one: %d\n", x);

  // Call add_one_pointer with the address of x
  add_one_pointer(&x);
  printf("After add_one_pointer: %d\n", x);

  // Create an integer pointer ptr that stores the address of x
  int* ptr = &x;

  // Call add_one_double_ptr with the address of ptr
  add_one_double_ptr(&ptr);
  printf("After add_one_double_ptr: %d\n", x);

  return 0;
}
