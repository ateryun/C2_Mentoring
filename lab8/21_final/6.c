#include <stdio.h>

int main() {
    unsigned long long a, b;
    printf("a와 b를 입력하세요: ");
    scanf("%llu %llu", &a, &b);

    unsigned long long f1 = 0, f2 = 1, f3;
    int count = 0;

    // 피보나치 수열을 생성하면서 a와 b 사이에 있는 수를 찾음
    while (f2 <= b) {
        if (f2 >= a) {
            printf("%llu ", f2);
            count++;
        }
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    printf("\n피보나치 수의 개수: %d\n", count);

    return 0;
}

