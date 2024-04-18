#include <stdio.h>

int main(void) {
    for (int i = 32; i < 127; i++) {
        for (int j = i; j < 127; j += 32) {
            printf("%d %X %c ", i, i, i);
        }
        printf("\n");
    }
    return 0;
}

