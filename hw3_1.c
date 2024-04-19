#include <stdio.h>
#include <stdlib.h>

void printNumbers(int start, int end, int reverse) {
	int count = 0;

	if(!reverse)  { // 역순이 아닐때, 
		for (int i = start; i<=end; i++) { 
			printf("%2d ", i); // 처음부터 끝까지 추가
			count++;
			if (count ==5) { //만약 count가 5가되었을때, 
				printf("\n"); // 줄 넘기기
				count =0; // count 초기화
			}
		}
	} else { // 역순일때
		for(int i = end; i >=start; i--)  // 끝부터 시작점까지
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

int main(int argc, char *argv[]) {
	// 마지막에서 두 번째와 세 번째 원소가 사용됨.
	int start = atoi(argv[argc - 2]); // ./hw3_2 -r 5 19 
	int end = atoi(argv[argc -1]); // start = 19, end = 5
	int reverse =0;

	if(argc == 4 && argv[1][0] == '-' && argv[1][1] == 'r') {
		reverse = 1; // -r이 들어온다면 역순으로 출력.
	}
	printNumbers(start,end, reverse);  

	return 0;
}
