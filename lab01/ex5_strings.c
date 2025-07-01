#include <stdio.h>
#include <string.h>

int main() {
  char src[] = "CS 61C";
  char dest[50];

  strcpy(dest, src);

  printf("Original string: %s\n", dest);
  printf("Length of string: %lu\n", strlen(dest));

  dest[3] = '-';

  printf("Modified string: %s\n", dest);
  printf("New length: %lu\n", strlen(dest));

  return 0;
}
