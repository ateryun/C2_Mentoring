#include <stdio.h>
#include <ctype.h>

int getLine(char s[], int lim) {
	int c, i =0;
	while(--lim >0 && (c=getchar()) != EOF && c !='\n')
		s[i++] = c;
	if ( c== '\n')
		s[i++] =c;
	s[i] = '\0';
	return i;
}
int calculator(int n, int prime, char op) {
    int sum = 0;
    switch (op) {
        case '+':
            sum = n + prime;
            break;
        case '-':
            sum = n - prime;
            break;
        case '*':
            sum = n * prime;
            break;
        case '/':
            sum = n / prime;
            break;
        case '%':
            sum = n % prime;
            break;
    }
    return sum;
}
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
int isPrime(int num) {
	if (num<=1)
		return 0;
	for(int i=2; i*i <=num; i++) {
		if(num % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	char operation;
	char state[20];
	int number;
	int count =0;

	getLine(state, 20);
	
	
	int i =0;
	while (state[i] != ' ') {
		i++;
	}
	state[i] = '\0';
	number = atoi(state);
	operation = state[i+1];

	printf("\n");
	for (int i =2; count <10; i++) {
		if(isPrime(i)) {
			int result = calculator(number, i, operation);
			printf("%d %c %d = %d\n", number, operation, i, result);
			count++;
		}
	}
	return 0;
}
