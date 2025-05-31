#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    const char *t1 = "Hello, World!";
    const char *t2 = "Goodbye, World!";
    int wt1 = strlen(t1);
    int wt2 = strlen(t2);
    int height, width;

    while (true) {
        getmaxyx(stdscr, height, width);
        clear();

        for (int i = 0; i < wt1; ++i) {
          mvaddch(height/2, (width - wt1)/2 + i, '-');
          mvaddch(height/2 - 1, (width - wt1)/2 + i, '-');
        }

        attron(COLOR_PAIR(1));
        mvprintw(height/2, (width - wt1)/2, t1);
        attroff(COLOR_PAIR(1));
        
        attron(COLOR_PAIR(2));
        mvprintw(height/2 + height/4, (width - wt2)/2, t2);    
        attroff(COLOR_PAIR(2));    

        refresh();
        napms(100);
    }

    endwin();
    return 0;
}

