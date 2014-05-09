#include <curses.h>
int main()
{
    int x = 5;
    int y = 5;
    int ch;
    initscr();
    start_color();
    use_default_colors();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    start_color ();
    while (1)
    {
        init_pair(1,COLOR_GREEN,COLOR_RED);
        attron(COLOR_PAIR(1));
        mvprintw(y, x, "O");
        ch = getch();
        if (ch == KEY_DOWN)
        {
            y++;
            clear();
        }
        if (ch == KEY_UP)
        {
            y--;
            clear();
        }
        if (ch == KEY_LEFT)
        {
            x--;
            clear();
        }
        if (ch == KEY_RIGHT)
        {
            x++;
            clear();
        }
        attroff(COLOR_PAIR(1));
        refresh();
    }

    endwin();
    return 0;
}
