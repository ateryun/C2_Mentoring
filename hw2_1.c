#include <stdio.h>


int main(void) {
	for(int i =33, j=0; i<127; i++) {
		printf("%d %X %C ", i,i,i);
		j++;
		if (j % 6==0)
			printf("\n");
	}
	return 0;
}

