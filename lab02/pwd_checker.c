#include <string.h>
#include <stdbool.h>
#include "pwd_checker.h"

bool check_range(char letter, char lower, char upper) {
    return letter >= lower && letter <= upper;
}

bool check_upper(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'A', 'Z')) {
            return true;
        }
        ++password;
    }
    return false;
}

bool check_lower(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'a', 'z')) {
            return true;
        }
        ++password;
    }
    return false;
}

bool check_number(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, '0', '9')) {
            return true;
        }
        ++password;
    }
    return false;
}

bool check_length(const char *password) {
    return strlen(password) >= 10;
}

bool check_name(const char *first_name, const char *last_name, const char *password) {
    return !strstr(password, first_name) && !strstr(password, last_name);
}

bool check_password(const char *first_name, const char *last_name, const char *password) {
    return check_length(password)
        && check_upper(password)
        && check_lower(password)
        && check_number(password)
        && check_name(first_name, last_name, password);
}
