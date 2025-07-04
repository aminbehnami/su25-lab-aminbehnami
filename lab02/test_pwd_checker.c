#include <string.h>
#include <stdbool.h>
#include "pwd_checker.h"

/* Returns true if the length of PASSWORD is at least 10, false otherwise */
bool check_length(const char *password) {
    return strlen(password) >= 10;
}

/* Returns true if LETTER is in the range [LOWER, UPPER], false otherwise */
bool check_range(char letter, char lower, char upper) {
    return letter >= lower && letter <= upper;
}

/* Returns true if PASSWORD contains at least one upper case letter, false otherwise */
bool check_upper(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'A', 'Z')) {
            return true;
        }
        password++;
    }
    return false;
}

/* Returns true if PASSWORD contains at least one lower case letter, false otherwise */
bool check_lower(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'a', 'z')) {
            return true;
        }
        password++;
    }
    return false;
}

/* Returns true if PASSWORD contains at least one number, false otherwise */
bool check_number(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, '0', '9')) {
            return true;
        }
        password++;
    }
    return false;
}

/* Returns true if the person's first and last name are NOT in the password, false otherwise */
bool check_name(const char *first_name, const char *last_name, const char *password) {
    return strstr(password, first_name) == NULL && strstr(password, last_name) == NULL;
}

/* Returns true if PASSWORD meets the conditions specified above */
bool check_password(const char *first_name, const char *last_name, const char *password) {
    return check_length(password) &&
           check_upper(password) &&
           check_lower(password) &&
           check_number(password) &&
           check_name(first_name, last_name, password);
}
