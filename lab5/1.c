#include <stdio.h>

int main(void) {
	int a[] = {1,2,3,4,5};
	int *p = a;
	int i ;

	for(int i = 0; i <5; i++) 
	{
		printf("a[%d]의 원소 : %d\n", i, a[i]);
	}
	i = 0;
	while(*p < 5) {
		printf("포인터 P의 %d번째 원소 : %d\n", *p, *p);
		p++;
	}
	return 0;
}
