#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    // Initialize ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    
    // Enable colors
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);

    // Get the screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Make sizes for the main window
    int winH = 20;
    int winW = 40;
    int winY = (yMax - winH) / 2;
    int winX = (xMax - winW) / 2;

    // Make sizes for the sub window
    int subH = 1;
    int subW = 2;
    int subY = (winH - subH) / 2;
    int subX = (winW - subW) / 2;

    // Main game loop
    int ch;
    while (1) {
      clear();
      refresh();

      // Create the main window
      WINDOW *mWin = newwin(winH, winW, winY, winX);
      box(mWin, 0, 0);
      wbkgd(mWin, COLOR_PAIR(1));
      wrefresh(mWin);

      // Create the sub window
      WINDOW *sWin = derwin(mWin, subH, subW, subY, subX);
      box(sWin, 0, 0);
      wbkgd(sWin, COLOR_PAIR(2));
      wrefresh(sWin);

      ch = getch();
      if (ch == KEY_DOWN && subY < winH - subH - 1) {
        subY++; 
      } 
      
      if (ch == KEY_UP && subY > 1) {
        subY--;
      }

      if (ch == KEY_LEFT && subX > 1) {
        subX--;
      }

      if (ch == KEY_RIGHT && subX < winW - subW - 1) {
        subX++;
      }

      refresh();
    }

    endwin();
    return 0;
}
