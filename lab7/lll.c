#include <stdio.h>

#define MAX_LINE_LENGTH 100
int main(int argc, char *argv[])
{
	FILE *fp = fopen("alice.txt","r");
	if (fp == NULL) {
		printf("Error\n");	
		return 1;
	}
	
	char line[MAX_LINE_LENGTH];
	
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s", line);
	}
	fclose(fp);
	
	return 0;

}

	
