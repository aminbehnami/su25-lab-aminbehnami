#include <string.h>
#include <stdbool.h>
#include "pwd_checker.h"

HEAD
bool check_length(const char *password) {
    return strlen(password) >= 10;

/* Returns true if the length of PASSWORD is at least 10, false otherwise */
bool check_length(const char *password) {
    int length = strlen(password);
    bool meets_len_req = (length >= 10);
    return meets_len_req;
 5473a67 (Fix pwd_checker: fully working version for Exercise 3)
}

bool check_range(char letter, char lower, char upper) {
HEAD
    return letter >= lower && letter <= upper;
}

bool check_upper(const char *password) {
    while (*password) {

    bool is_in_range = (letter >= lower && letter <= upper);
    return is_in_range;
}

/* Returns true if PASSWORD contains at least one upper case letter */
bool check_upper(const char *password) {
    while (*password != '\0') {
 5473a67 (Fix pwd_checker: fully working version for Exercise 3)
        if (check_range(*password, 'A', 'Z')) {
            return true;
        }
        password++;
    }
    return false;
}

 HEAD
bool check_lower(const char *password) {
    while (*password) {

/* Returns true if PASSWORD contains at least one lower case letter */
bool check_lower(const char *password) {
    while (*password != '\0') {
 5473a67 (Fix pwd_checker: fully working version for Exercise 3)
        if (check_range(*password, 'a', 'z')) {
            return true;
        }
        password++;
    }
    return false;
}

 HEAD
bool check_number(const char *password) {
    while (*password) {

/* Returns true if PASSWORD contains at least one number */
bool check_number(const char *password) {
    while (*password != '\0') {
 5473a67 (Fix pwd_checker: fully working version for Exercise 3)
        if (check_range(*password, '0', '9')) {
            return true;
        }
        password++;
    }
    return false;
}

 HEAD
bool check_name(const char *first, const char *last, const char *password) {
    return strstr(password, first) == NULL && strstr(password, last) == NULL;
}

bool check_password(const char *first, const char *last, const char *password) {
    return check_length(password)
        && check_upper(password)
        && check_lower(password)
        && check_number(password)
        && check_name(first, last, password);

/* Returns true if PASSWORD does not contain first or last name */
bool check_name(const char *first_name, const char *last_name, const char *password) {
    return strstr(password, first_name) == NULL && strstr(password, last_name) == NULL;
}

/* Returns true if PASSWORD meets all conditions */
bool check_password(const char *first_name, const char *last_name, const char *password) {
    bool length = check_length(password);
    bool upper = check_upper(password);
    bool lower = check_lower(password);
    bool number = check_number(password);
    bool name = check_name(first_name, last_name, password);
    return length && upper && lower && number && name;
 5473a67 (Fix pwd_checker: fully working version for Exercise 3)
}
