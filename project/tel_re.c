#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 30
#define MAX_PHONENUMBER_LEN 20
#define MAX_MEMO_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONENUMBER_LEN];
    char memo[MAX_MEMO_LEN];
} Info_Phone;

Info_Phone phonebook[MAX_ELEMENTS];
int Info_count = 0;

// 전화번호부 파일을 로드하는 함수
void Load_PhoneBook(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        if (Info_count >= MAX_ELEMENTS) {
            break;
        }

        // 줄 끝 공백 제거
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, ":");
        if (token && strlen(token) > 0) {
            strncpy(phonebook[Info_count].name, token, MAX_NAME_LEN);
        } else {
            continue;  // 이름이 없으면 다음 줄로 이동
        }
        token = strtok(NULL, ":");
        if (token && strlen(token) > 0) {
            strncpy(phonebook[Info_count].phone, token, MAX_PHONENUMBER_LEN);
        } else {
            strncpy(phonebook[Info_count].phone, "", MAX_PHONENUMBER_LEN);
        }
        token = strtok(NULL, ":");
        if (token && strlen(token) > 0) {
            strncpy(phonebook[Info_count].memo, token, MAX_MEMO_LEN);
        } else {
            strncpy(phonebook[Info_count].memo, "", MAX_MEMO_LEN);
        }
        Info_count++;
    }
    fclose(fp);
}

// 전화번호부 파일을 저장하는 함수
void save_phonebook(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < Info_count; i++) {
        // 이름이 없는 항목은 저장하지 않음
        if (strlen(phonebook[i].name) > 0) {
            fprintf(file, "%s:%s:%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
        }
    }
    fclose(file);
}

// 전화번호 검색 함수
void search_entry() {
    char search_name[MAX_NAME_LEN];
    echo();
    mvprintw(LINES - 2, 0, "Enter name to search: ");
    getstr(search_name);
    noecho();

    clear();  // 화면 초기화
    int found = 0;
    for (int i = 0; i < Info_count; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {//Bae 입력하면 Bae랑 Baek같이 나오는 문제 발견해서 고침요
            mvprintw(i, 0, "Name: %s, Phone: %s, Memo: %s", phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
            found = 1;
        }
    }
    if (!found) {
        mvprintw(0, 0, "No entries found with name containing '%s'", search_name);
    }
    refresh();
    getch();
}

// 전화번호 추가 함수
void add_entry() {
    if (Info_count >= MAX_ELEMENTS) {
        mvprintw(LINES - 2, 0, "Phonebook is full. Cannot add more entries.");
        refresh();
        getch();
        return;
    }

    echo();
    mvprintw(LINES - 4, 0, "Enter name: ");
    getstr(phonebook[Info_count].name);
    mvprintw(LINES - 3, 0, "Enter phone: ");
    getstr(phonebook[Info_count].phone);
    mvprintw(LINES - 2, 0, "Enter memo: ");
    getstr(phonebook[Info_count].memo);
    noecho();

    Info_count++;
}

// 전화번호 삭제 함수
void delete_entry() { //이름같은거있으면 먼저 입력한게 먼저 삭제되더라(just참고)
    char delete_name[MAX_NAME_LEN];
    echo();
    mvprintw(LINES - 2, 0, "Enter the name to delete: ");
    getstr(delete_name);
    noecho();

    clear();  // 화면 초기화
    int found = 0;
    for (int i = 0; i < Info_count; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            for (int j = i; j < Info_count - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            Info_count--;
            found = 1;
            break;
        }
    }
    if (found) {
        mvprintw(0, 0, "Entry deleted.");
    } else {
        mvprintw(0, 0, "No entry found with name '%s'", delete_name);
    }
    refresh();
    getch();
}

// 전화번호 목록 출력 함수
void list_entry() {
    clear();  // 화면 초기화
    for (int i = 0; i < Info_count; i++) {
        mvprintw(i, 0, "Name: %s, Phone: %s, Memo: %s", phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
    }
    refresh();
    getch();
}

// 메뉴 출력 함수
void print_menu(WINDOW *menu_win, int highlight) {
    char *choices[] = {
        "1. Search",
        "2. Add",
        "3. Delete",
        "4. List",
        "5. Save and Exit"
    };

    int n_choices = sizeof(choices) / sizeof(char *);
    box(menu_win, 0, 0);
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, i + 1, 1, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, i + 1, 1, "%s", choices[i]);
        }
    }
    wrefresh(menu_win);
}

int main() {
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();  // NCURSES 초기화
    clear();
    noecho();
    cbreak();
    menu_win = newwin(10, 40, 4, 4);
    keypad(menu_win, TRUE);

    Load_PhoneBook("data.txt");  // 전화번호부 로드

    while (1) {
        clear();//add & list 함수 쓴 다음에 초기화 안되는 문제 발생해서 넣음요
        mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
        refresh();
        print_menu(menu_win, highlight);  // 메뉴 출력
        while (1) {
            c = wgetch(menu_win);
            switch (c) {
                case KEY_UP:
                    if (highlight == 1)
                        highlight = 5;
                    else
                        --highlight;
                    break;
                case KEY_DOWN:
                    if (highlight == 5)
                        highlight = 1;
                    else
                        ++highlight;
                    break;
                case 10:  // Enter 키를 누르면 선택 완료
                    choice = highlight;
                    break;
                default:
                    break;
            }
            print_menu(menu_win, highlight);  // 선택된 항목을 반영하여 메뉴 다시 그리기
            if (choice != 0)
                break;
        }

        clear();  // 화면 초기화
        refresh();

        switch (choice) {
            case 1:
                search_entry();  // 전화번호 검색
                break;
            case 2:
                add_entry();  // 전화번호 추가
                break;
            case 3:
                delete_entry();  // 전화번호 삭제
                break;
            case 4:
                list_entry();  // 전화번호 목록 출력
                break;
            case 5:
                save_phonebook("data.txt");  // 전화번호부 저장
                endwin();  // NCURSES 종료
                return 0;
        }
        choice = 0;  // 선택 항목 초기화하여 메뉴 반복
    }

    endwin();  // NCURSES 종료
    return 0;
}


