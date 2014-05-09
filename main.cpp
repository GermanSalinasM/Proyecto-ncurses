#include <curses.h>
int main()
{
    int x = 5;
    int y = 5;
    int ch;
    initscr();
    start_color();//da color
    use_default_colors();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    start_color ();
    while (1)
    {
        init_pair(1,COLOR_GREEN,COLOR_RED);
        attron(COLOR_PAIR(1));//aplica color
        mvprintw(y, x, "O");
        ch = getch();
        if (ch == KEY_DOWN)//se mueve hacia abajo
        {
            y++;
            clear();
        }
        if (ch == KEY_UP)//se mueve hacia arriba
        {
            y--;
            clear();
        }
        if (ch == KEY_LEFT)//se mueve hacia izq.
        {
            x--;
            clear();
        }
        if (ch == KEY_RIGHT)//se mueve hacia derecha
        {
            x++;
            clear();
        }
        attroff(COLOR_PAIR(1));//deja de aplicar color
        refresh();
    }

    endwin();
    return 0;
}
