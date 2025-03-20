#include <stdint.h>
#include <stdio.h>

int main(void) {
    int64_t a = 32;
    int b = 0xffaa33;
    int c = 0755;          // octal
    int d = 0b01010101010; // binary

    printf("%d\n", a);
    printf("%x\n", b); // hexadecimal
    printf("%o\n", c); // octal
    printf("%b\n", d); // bi
}