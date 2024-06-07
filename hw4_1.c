#include <stdio.h>
void dtob(int i) {
	if(n>1) dtob(n/2);
	printf("%d", n%2);

}
int main(void) {
	int i;
	printf("십진수를 입력하세요 : %d\n");
	scanf("%d\n", &i);
	printf("%d", i);
	return 0;
}
	
