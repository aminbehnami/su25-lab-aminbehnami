#include <assert.h>
#include <stdio.h>
#include "pwd_checker.h"

int main() {
    printf("Running tests...\n\n");

    const char *test1_first = "Abraham";
    const char *test1_last = "Garcia";
    const char *test1_pwd = "qrtv?,mp!ltrA0b13rab4ham";
    bool test1 = check_password(test1_first, test1_last, test1_pwd);
    assert(test1);

    const char *test2_first = "Nina";
    const char *test2_last = "Park";
    const char *test2_pwd = "Ninapark1";
    bool test2 = check_password(test2_first, test2_last, test2_pwd);
    assert(!test2);

    const char *test3_first = "Lee";
    const char *test3_last = "Kim";
    const char *test3_pwd = "V1br4ntLee";
    bool test3 = check_password(test3_first, test3_last, test3_pwd);
    assert(!test3);

    const char *test4_first = "Tony";
    const char *test4_last = "Tran";
    const char *test4_pwd = "MyPwd12345";
    bool test4 = check_password(test4_first, test4_last, test4_pwd);
    assert(test4);

    printf("Congrats! You have passed all of the test cases!\n");
    return 0;
}
