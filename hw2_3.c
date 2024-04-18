#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

int getLine(char *line, int max) {
	int c, i =0;
	while(--max >0 && (c=getchar()) != EOF && c !='\n')
		line[i++] = c;
	if ( c== '\n')
		line[i++] =c;
	line[i] = '\0';
	return i;
}
int main(int argc, char *argv[])
{
	char line[MAXLINE]; //라인 깔고
	long lineno = 0; // 라인에 맞는 숫자 설정
	int c, except = 0, number =0, found =0; // 
	// found가 0 이나 ' '이면 오름, 1이면 내림

	while(--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case '0':
					except =1;
					break;
				case ' ':
					except = 1;
				case '1':
					number =1;
					break;
				default:
					printf("not option");
					argc = 0;
					found = -1;
					break;
			}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else 
		while (getLine(line, MAXLINE) >0) {
			lineno++;
			if ((strstr(line, *argv) != NULL)!= except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}
