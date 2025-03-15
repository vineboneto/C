#include <stdbool.h>
#include <stdio.h>

int f(int x, bool is_added, bool is_squared, bool is_not) {
    if (is_added)
        x += x;
    if (is_squared)
        x *= x;
    if (is_not)
        x = ~x;
    return x;
}

typedef unsigned int t_flag;
#define FLAG_A (1 << 0)
#define FLAG_B (1 << 1)
#define FLAG_C (1 << 2)

int f_bit_flag(int x, t_flag flags) {
    if (flags & FLAG_A)
        x += x;
    if (flags & FLAG_B)
        x *= x;
    if (flags & FLAG_C)
        x = ~x;
    return x;
}

typedef enum {
    FLAG_ENUM_A = (1 << 0),
    FLAG_ENUM_B = (1 << 2),
    FLAG_ENUM_C = (1 << 3)
} t_flag_enum;

int f_bit_flag_enum(int x, t_flag_enum flags) {
    if (flags & FLAG_ENUM_A)
        x += x;
    if (flags & FLAG_ENUM_B)
        x *= x;
    if (flags & FLAG_ENUM_C)
        x = ~x;
    return x;
}

int main() {
    printf("%d\n", f(1234, false, false, false));
    printf("%d\n", f(1234, true, false, false));
    printf("%d\n", f(1234, false, true, true));

    printf("%d\n", f_bit_flag(1234, 0));
    printf("%d\n", f_bit_flag(1234, FLAG_A));
    printf("%d\n", f_bit_flag(1234, FLAG_B | FLAG_C));

    printf("%d\n", f_bit_flag_enum(1234, 0));
    printf("%d\n", f_bit_flag_enum(1234, FLAG_A));
    printf("%d\n", f_bit_flag_enum(1234, FLAG_B | FLAG_C));
}