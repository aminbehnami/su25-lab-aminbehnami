#include <string.h>
#include <stdbool.h>
#include "pwd_checker.h"

/*
Password checker

Requirements:
- Password must be at least 10 characters
- Password must contain at least
    - 1 upper case letter
    - 1 lower case letter
    - 1 number
- Password cannot contain the person's first name or last name (case sensitive)
*/

/* Returns true if the length of PASSWORD is at least 10, false otherwise */
bool check_length(const char *password) {
    return strlen(password) >= 10;
}

/* Returns true if LETTER is in the inclusive range [LOWER, UPPER] */
bool check_range(char letter, char lower, char upper) {
    return letter >= lower && letter <= upper;
}

/* Returns true if PASSWORD contains at least one upper case letter */
bool check_upper(const char *password) {
    while (*password) {
        if (check_range(*password, 'A', 'Z')) return true;
        password++;
    }
    return false;
}

/* Returns true if PASSWORD contains at least one lower case letter */
bool check_lower(const char *password) {
    while (*password) {
        if (check_range(*password, 'a', 'z')) return true;
        password++;
    }
    return false;
}

/* Returns true if PASSWORD contains at least one number */
bool check_number(const char *password) {
    while (*password) {
        if (check_range(*password, '0', '9')) return true;
        password++;
    }
    return false;
}

/* Returns true if the person's first and last name are NOT in the password */
bool check_name(const char *first_name, const char *last_name, const char *password) {
    return strstr(password, first_name) == NULL && strstr(password, last_name) == NULL;
}

/* Returns true if PASSWORD meets all criteria */
bool check_password(const char *first_name, const char *last_name, const char *password) {
    bool length = check_length(password);
    bool upper = check_upper(password);
    bool lower = check_lower(password);
    bool number = check_number(password);
    bool name = check_name(first_name, last_name, password);

    return length && upper && lower && number && name;
}
