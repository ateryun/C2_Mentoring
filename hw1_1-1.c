#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 1000

// 문자열을 입력받는 함수
int getLine(char s[], int lim) {
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// 문자열을 실수형으로 변환하는 함수
double atof(const char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

// 문자열을 정수형으로 변환하는 함수
int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for (n=0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

// 문자열로 표현된 계산식을 계산하는 함수
double calculate(char s[]) {
    double result = 0.0;
    double operand = 0.0;
    char operator = '+';
    int i = 0;

    while (s[i] != '\0') {
        if (isdigit(s[i]) || s[i] == '.') { // 숫자인 경우
            char num[MAXLINE];
            int j = 0;
            while (isdigit(s[i]) || s[i] == '.') { // 숫자를 추출하여 num 배열에 저장
                num[j++] = s[i++];
            }
            num[j] = '\0';

            // 정수형으로 변환
            int int_operand = atoi(num);

            switch (operator) {
                case '+': // 덧셈 연산
                    result += int_operand;
                    break;
                case '-': // 뺄셈 연산
                    result -= int_operand;
                    break;
                case '*': // 곱셈 연산
                    result *= int_operand;
                    break;
                case '/': // 나눗셈 연산
                    if (int_operand != 0) {
                        result /= int_operand;
                    } else {
                        printf("Error: 0으로 나눌 수 없습니다.\n");
                        return 0.0;
                    }
                    break;
                case '%': // 나머지 연산
                    if (int_operand != 0) {
                        int int_result = (int)result; // result를 정수로 변환
                        result = int_result % int_operand; // 정수형으로 나머지 계산
                    } else {
                        printf("Error: 0으로 나눌 수 없습니다.\n");
                        return 0.0;
                    }
                    break;
            }
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%') { // 연산자인 경우
            operator = s[i];
            i++;
        } else if (isspace(s[i])) { // 공백 문자인 경우
            i++;
        } else { // 그 외의 경우
            printf("Error: 연산자를 다시 입력해주세요. '%c'\n", s[i]);
            return 0.0;
        }
    }
    return result;
}

// 메인 함수
int main(void) {
    char line[MAXLINE];

    // 사용자로부터 문자열을 입력받음
    if (getLine(line, MAXLINE) > 0) {
        // 계산 결과를 출력
        double result = calculate(line);
        printf("Result: %lf\n", result);
    }
    return 0;
}

