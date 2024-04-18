#include <stdio.h>
#include <stdlib.h>

void printNumbers(int start, int end, int reverse) {
	int count = 0;

	if(!reverse) {
		for (int i = start; i<=end; i++) {
			printf("%2d ", i);
			count++;
			if (count ==5) {
				printf("\n");
				count =0;
			}
		}
	} else {
		for(int i = end; i >=start; i--)
		{
			printf("%2d ", i);
			count++;
			if (count ==5) {
				printf("\n");
				count =0;
			}
		}
	}

	if (count !=0) {
		printf("\n");
	}
}

int main(int argc, char*argv[]) {
	int start = atoi(argv[argc - 2]);
	int end = atoi(argv[argc -1]);
	int reverse =0;

	if(argc == 4 && argv[1][0] == '-' && argv[1][1] == 'r') {
		reverse = 1;
	}
	printNumbers(start,end, reverse);

	return 0;
}
