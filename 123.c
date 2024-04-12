#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

int getLine(char s[], int lim) {
	int c, i =0;
	while(--lim >0 && (c=getchar()) != EOF && c !='\n') 
		s[i++] = c;
	if ( c== '\n')
		s[i++] =c;
	s[i] = '\0';
	return i;
}

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
double calculate(char s[]) {
    double result = 0.0;
    double operand = 0.0;
    char operator = '+';
    int i = 0;

    while (s[i] != '\0') {
        if (isdigit(s[i]) || s[i] == '.') {
            char num[MAXLINE];
	    int j =0;
            while (isdigit(s[i]) || s[i] == '.') {
		    num[j++] = s[i++];
	    }
	    num[j] = '\0';
	    operand = atof(num);
      
            switch (operator) {
                case '+':
                    result += operand;
                    break;
                case '-':
                    result -= operand;
                    break;
                case '*':
                    result *= operand;
                    break;
		case '%':
		    int result = 0;
		    int operand = 0;
		    result %= operand;
		    break;
                case '/':
                    if (operand != 0.0) {
                        result /= operand;
                    } else {
                        printf("Error: 0으로 나눌 수 없습니다.\n");
                        return 0.0;
                    }
                    break;
            }
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%') {
            operator = s[i];
            i++;
        } else if (isspace(s[i])) {
            i++;
        } else {
            printf("Error: 연산자를 다시 입력해주세요. '%c'\n", s[i]);
            return 0.0;
        }
    }
    return result;
}

int main(void) {
    char line[MAXLINE];

    if (getLine(line, MAXLINE) > 0) {
        double result = calculate(line);
        printf("Result: %lf\n", result);
    }
    return 0;
}
