#include <string.h>
#include <stdbool.h>
#include "pwd_checker.h"

/* Returns true if the length of PASSWORD is at least 10, false otherwise */
bool check_length(const char *password) {
    int length = strlen(password);
    bool meets_len_req = (length >= 10);
    return meets_len_req;
}

/* Returns true if LETTER is in the range [LOWER, UPPER], false otherwise */
bool check_range(char letter, char lower, char upper) {
    bool is_in_range = (letter >= lower && letter <= upper);
    return is_in_range;
}

/* Returns true if PASSWORD contains at least one upper case letter, false otherwise */
bool check_upper(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'A', 'Z')) {
            return true;
        }
        ++password;
    }
    return false;
}

/* Returns true if PASSWORD contains at least one lower case letter, false otherwise */
bool check_lower(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'a', 'z')) {
            return true;
        }
        ++password;
    }
    return false;
}

/* Returns true if PASSWORD contains at least one number, false otherwise */
bool check_number(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, '0', '9')) {
            return true;
        }
        ++password;
    }
    return false;
}

/* Returns true if the person's first and last name are NOT in the password */
bool check_name(const char *first_name, const char *last_name, const char *password) {
    const char *first = strstr(password, first_name);
    const char *last = strstr(password, last_name);
    return (!first && !last);
}

/* Returns true if PASSWORD meets all criteria */
bool check_password(const char *first_name, const char *last_name, const char *password) {
    bool length = check_length(password);
    bool upper = check_upper(password);
    bool lower = check_lower(password);
    bool number = check_number(password);
    bool name = check_name(first_name, last_name, password);
    return (length && upper && lower && number && name);
}
