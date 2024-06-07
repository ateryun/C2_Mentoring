#include <stdio.h>

void printBinary(unsigned int n) {
    int started = 0; // 1이 나타났는지 여부를 체크하는 플래그
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        if ((n >> i) & 1) {
            started = 1; // 1이 나타났으므로 플래그 설정
        }
        if (started) {
            printf("%u", (n >> i) & 1);
        }
    }
    if (!started) {
        printf("0"); // n이 0인 경우를 처리
    }
}

int main() {
    unsigned int n;
    printf("10진수를 입력하세요: ");
    scanf("%u", &n);

    printf("2진수: ");
    printBinary(n);
    printf("\n");

    return 0;
}

