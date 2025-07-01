#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "CS 61C";       // source string
    char dest[50];               // enough room for string + null terminator

    strcpy(dest, src);           // copy string

    printf("Original string: %s\n", dest);
    printf("Length of string: %lu\n", strlen(dest));

    dest[3] = '-';               // mutate the string: change '6' to '-'

    printf("Modified string: %s\n", dest);
    printf("New length: %lu\n", strlen(dest));

    return 0;
}
