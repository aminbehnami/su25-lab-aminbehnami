#include <stdio.h>
#include <string.h>

typedef struct {
  char name[50];
  int id;
} Student;

void print_student(Student s) {
  printf("Student Name: %s\n", s.name);
  printf("Student ID: %d\n", s.id);
}

void update_name(Student* s, const char* new_name) {
  strcpy(s->name, new_name);
}

int main() {
  Student s1;
  strcpy(s1.name, "Alice");
  s1.id = 12345;

  print_student(s1);

  update_name(&s1, "Bob");
  printf("\nAfter update:\n");
  print_student(s1);

  return 0;
}
