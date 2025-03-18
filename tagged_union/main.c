#include <stdbool.h>
#include <stdio.h>

enum tag {
    TAG_BOOL,
    TAG_INT,
    TAG_FLOAT,
};

struct dynamic {
    enum tag tag;
    union {
        bool b;
        int i;
        float f;
    } value;
};

int main(void) {
    struct dynamic d;
    d.tag = TAG_INT;
    d.value.i = 42;

    switch (d.tag) {
    case TAG_BOOL:
        printf("bool: %d", d.value.b);
        break;
    case TAG_INT:
        printf("int: %d", d.value.i);
        break;
    case TAG_FLOAT:
        printf("float: %d", d.value.f);
        break;
    }
    return 0;
}