#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	while(b !=0) {
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}//최대 공약수

int lcm(int a, int b, int gcd_value) {
	return (a/gcd_value) *b;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "사용법 %s itg1 itg2\n", argv[0]);
		return 1;
	}
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	if (num1 <=0 || num2 <=0) {
		fprintf(stderr, "양수여야함,");
		return 1;
	}

	int gcd_value = gcd(num1, num2);
	int lcm_value = lcm(num1, num2, gcd_value);

	printf("정수 1 %d, 정수2 %d\n", num1, num2);
	printf("최대공약수 : %d\n", gcd_value);
	printf("최소공배수 : %d\n", lcm_value);
	return 0;
}
