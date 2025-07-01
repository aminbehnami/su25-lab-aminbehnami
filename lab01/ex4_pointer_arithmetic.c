#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t arr[] = {100, 200, 300};  // 4-byte ints
    int32_t* p = arr;

    printf("arr[0] = %d\n", arr[0]);
    printf("arr[2] = %d\n", arr[2]);

    printf("Address of arr[0]: %p\n", (void*)&arr[0]);
    printf("Address of arr[2]: %p\n", (void*)&arr[2]);

    printf("Using pointer: *(p + 2) = %d\n", *(p + 2));
    printf("Address from pointer math: %p\n", (void*)(p + 2));

    return 0;
}
