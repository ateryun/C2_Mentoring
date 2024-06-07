#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
	return strcmp(*(const char **)a, *(const char **)b);
}

int compare_re(const void *a, const void *b) {
	return strcmp(*(const char **)b, *(const char **)a);
}
int main(int argc, char *argv[]) {
	if (argc <2) {
		fprintf(stderr, "%s [-r] word1 word2.. wordN\n", argv[0]);
		return 1;
	}
	int reverse =0;
	int start_index = 1;

	if (strcmp(argv[1], "-r") ==0) {
		reverse = 1;
		start_index = 2;
	}
	if (start_index >=argc) {
		fprintf(stderr, "Not Enterned the words\n");
		return 1;
	}
	char **words = argv+start_index;
	int word_count = argc - start_index;

	if(reverse) {
		qsort(words, word_count, sizeof(char *), compare_re);
	} else {
		qsort(words, word_count, sizeof(char *), compare);
	}

	for (int i = 0; i <word_count; i++) {
		printf("%s ", words[i]);
	}
	printf("\n");

	return 0;
}

