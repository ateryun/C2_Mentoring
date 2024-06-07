#include <stdio.h>
#include <string.h>

#define WORDLEN_MAX 100
#define LINE_MAX 100
void swap(char v[][WORDLEN_MAX], int i, int j){//2차원 배열에 들어가는 문자열을 swap
    if (i==j)
        return;
    char temp[WORDLEN_MAX];
    strcpy(temp, v[i]);
    strcpy(v[i], v[j]);
    strcpy(v[j], temp);
}

void sort(char array[][WORDLEN_MAX], int left, int right){// 2차원 배열의 qsort구현
    int i, last;

    if (left >= right)
        return;
    swap(array, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; ++i)
        if (strcmp(array[i], array[left]) < 0)
            swap(array, ++last, i);
    swap(array, left, last);
    sort(array, left, last - 1);
    sort(array, last + 1, right);
}

int main(int argc, char *argv[]) {
	int re = 0;
	if(argc <2) return 1;
	if(strcmp(
