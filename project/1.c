#include <ncurses.h>
int main(void)
{
	initscr();
	cbreak();
	noecho();
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	WINDOW *menuwin = newwin(6, xMax-12, yMax-8, 5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);
	char *choices[5] = {"search", "Add", "Delete", "list","Exit"};
	int choice;
	int highlight = 0;
	while (1) {
		for (int i = 0; i <5; i++) {
			if (i == highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i+1, 1, choices[i]);
			wattroff(menuwin, A_REVERSE);
			}
		choice = wgetch(menuwin);
		switch (choice) {
			case KEY_UP:
				highlight--;
				break;
			case KEY_DOWN:
				highlight++;
				break;
			default:
				break;
		}
		if (choice == 10)
			break;
	}
	printw("Your choice is: %s", choices[highlight]);
	getch();
	endwin();
	return 0;
}
