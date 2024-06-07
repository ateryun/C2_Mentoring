#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("파일을 열수 없습니다.");
		return 1;
	}
	int lines = 0, words = 0, chars = 0;
	int in_word = 0;
	char ch;

	while((ch = fgetc(fp)) != EOF) {
		putchar(ch);
		chars++;

		if (ch == '\n'){
			lines++;
		}
		if (isspace(ch)) {
			in_word = 0;
		} else if (!in_word) {
			in_word = 1;
			words++;
		}
	}
	fclose(fp);
	printf("%d ", lines);
	printf("%d ", words);
	printf("%d ", chars);
	printf("%s ",argv[1]);
	return 0;
}
