#include <stdio.h>

// macro
#define ARRAY_LEN(a) (sizeof a / sizeof a[0])

int main() {
    int a = 1;
    int xs[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *xs_ptr = xs;

    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(long));
    printf("%zu\n", sizeof a);
    printf("%zu\n", sizeof xs);
    printf("%zu\n",
           sizeof xs_ptr); // somente 8 bytes que é o tamanho de um ponteiro,
                           // sizeof define o tamanho em bytes na hora de
                           // compilar algo, e em tempo de compilação não há
                           // como saber que tem um array por trás do ponteiro
    printf("%zu\n", ARRAY_LEN(xs));

    return 0;
}
