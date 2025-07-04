#include <stdio.h>
#include <stdlib.h>  // added for malloc

struct Course {
    char* name;
    int number;
};

// Takes in a name and a number and returns a pointer to a Course struct
struct Course* make_course(char* name, int number) {
    struct Course* new_course = malloc(sizeof(struct Course));
    new_course->name = name;         // fixed: removed dereference
    new_course->number = number;
    return new_course;               // fixed: return the pointer directly
}

int main() {
    struct Course* cs61c = make_course("CS61C", 61);
    printf("%s %d\n", cs61c->name, cs61c->number);
    return 0;
}
