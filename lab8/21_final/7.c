#include <stdio.h>

int main() {
    unsigned int n;
    printf("10진수를 입력하세요: ");
    scanf("%u", &n);

    printf("2진수: ");
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
    }
    printf("\n");

    return 0;
}

