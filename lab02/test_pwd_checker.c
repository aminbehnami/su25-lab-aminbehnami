#include <string.h>
#include <stdbool.h>
#include "pwd_checker.h"

bool check_length(const char *password) {
    return strlen(password) >= 10;
}

bool check_range(char letter, char lower, char upper) {
    return letter >= lower && letter <= upper;
}

bool check_upper(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'A', 'Z')) return true;
        password++;
    }
    return false;
}

bool check_lower(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'a', 'z')) return true;
        password++;
    }
    return false;
}

bool check_number(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, '0', '9')) return true;
        password++;
    }
    return false;
}

bool check_name(const char *first_name, const char *last_name, const char *password) {
    return strstr(password, first_name) == NULL && strstr(password, last_name) == NULL;
}

bool check_password(const char *first_name, const char *last_name, const char *password) {
    bool lower = check_lower(password);
    bool length = check_length(password);
    bool name = check_name(first_name, last_name, password);
    bool number = check_number(password);
    bool upper = check_upper(password);

    return lower && length && name && number && upper;
}
