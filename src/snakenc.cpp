#include <ncurses.h>

int main(int argc, char **argv) {
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);

  while (true) {
    clear();
    refresh();
  }

  endwin();
  return 0;
}
