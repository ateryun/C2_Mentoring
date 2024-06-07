#include <stdio.h>
#include <time.h>

int isLeapYear(int year) {
	if ((year % 4 == 0 && year %100 != 0) || (year % 400 == 0)) {	
		return 1;
	}
	return 0;
}
int getDaysInMonth(int year, int month) {
	int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && isLeapYear(year)) {
		return 29;
	}
	return days_in_month[month-1];
}

int main() {
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    int year = today->tm_year + 1900;
    int month = today->tm_mon + 1;
    int day = today->tm_mday;

    // 해당 월의 첫 번째 날의 요일 계산
    struct tm first_day_of_month = { .tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = 1 };
    mktime(&first_day_of_month);
    int start_day = first_day_of_month.tm_wday;

    int days_in_month = getDaysInMonth(year, month);

    // 달력 출력
    printf("     %d년 %d월\n", year, month);
    printf(" 일 월 화 수 목 금 토\n");

    // 시작 요일에 맞춰 공백 출력
    for (int i = 0; i < start_day; i++) {
        printf("   ");
    }

    // 날짜 출력
    for (int i = 1; i <= days_in_month; i++) {
        printf("%3d", i);
        if ((start_day + i) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}

