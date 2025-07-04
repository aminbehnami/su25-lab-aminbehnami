#include <stdio.h>
#include <stdbool.h>
#include "pwd_checker.h"

int main() {
    printf("Running tests...\n\n");

    const char *test1_first = "Abraham";
    const char *test1_last = "Garcia";
    const char *test1_pwd = "Zyx987!@#q";  // Valid: 10+ chars, upper, lower, number, no names

    bool test1 = check_password(test1_first, test1_last, test1_pwd);

    printf("Test1 result: %d\n", test1);  // Should be 1 (true)
    return 0;
}
