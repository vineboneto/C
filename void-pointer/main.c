#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/**
 * fill memory with a constant byte
 */
void *my_memset(void *data, uint8_t c, size_t n) {
    uint8_t *data_as_bytes = (uint8_t *)data;
    for (size_t i = 0; i < n; i++) {
        data_as_bytes[i] = c;
    }
    return data;
}

void map(void *xs, size_t n, size_t size, void (*f)(void *)) {
    uint8_t *xs_as_bytes = (uint8_t *)xs;

    for (size_t i = 0; i < n; i++) {
        f(&xs_as_bytes[i * size]);
    }
}

void square(void *x) {
    int *p = x;
    *p = *p * *p;
}

int main() {
    int xs[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", xs[i]);
    }
    printf("\n");
    my_memset(xs, 0, sizeof xs);
    for (int i = 0; i < 5; i++) {
        printf("%d ", xs[i]);
    }
    printf("\n");

    int xs_2[5] = {1, 2, 3, 4, 5};
    map(xs_2, 5, sizeof(int), square);
    for (int i = 0; i < 5; i++) {
        printf("%d ", xs_2[i]);
    }
    printf("\n");

    int a = 3;
    void *p = &a;

    // unsigned int, memory address
    printf("%p\n", p);

    // Error, not knows type is
    // printf("%p\n", *p);

    // cast to type int, and deference to get value
    printf("%d\n", *(int *)p);

    return 0;
}