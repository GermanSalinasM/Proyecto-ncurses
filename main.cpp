#include <list>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
class snake {
 private:
  int x, y;
 public:
  snake(int a, int b) {
   x = a;
   y = b;
  }
  int getX() { return x; }
  int getY() { return y; }
};
int main() {
 // inicio
 srand ( time(NULL) );
 initscr();
 WINDOW *borde = newwin(20,40,0,-1);
 start_color();
 start_color();//da color
 noecho();
 curs_set(0);
 keypad(stdscr, TRUE);
 timeout(100);

 std::list<snake> snakes;
 std::list<snake>::iterator it;
 bool salir = false;
 int puntos = 0;
 int dir = 2;
 int comida_x = rand() % 38;
 int comida_y = rand() % 19;
 int ch;

 for(int i = 0; i < 2; i++) // puntos de partida de snake
  snakes.push_front(snake(3+i,3));

 while(!salir) {
     // entrada
     ch = getch();
     switch(ch) {
      case KEY_UP:
       dir = 1;
       break;
      case KEY_RIGHT:
       dir = 2;
       break;
      case KEY_DOWN:
       dir = 3;
       break;
      case KEY_LEFT:
       dir = 4;
       break;
      case 'p':
       salir = true;
       break;
     }

     // como se mueve
     snake logica = snakes.front();
     int x = logica.getX();
     int y = logica.getY();
     if(dir == 1) y--; // hacia arriba
     else if(dir == 2) x++; // hacia la derecha
     else if(dir == 3) y++; // hacia abajo
     else if(dir == 4) x--; // hacia abajo
box(borde, '-', '+');
touchwin(borde);
wrefresh(borde);
     snakes.push_front(snake(x, y));
     if(x == comida_x && y == comida_y) {
      comida_x = rand() % 38;
      comida_y = rand() % 19;
   puntos++;
     } else
      snakes.pop_back();

     if(y > 18 || x > 37 || y < 0 || x < 0) // colision con los bordes
      salir = true;
      // salida
       touchwin(borde);
    wrefresh(borde);
     erase();
     init_pair(7,COLOR_WHITE,COLOR_WHITE);
        attron(COLOR_PAIR(7));//aplica color
        attron(COLOR_PAIR(7));
     mvaddch(comida_y,comida_x,'o');
     attroff(COLOR_PAIR(7));
    attroff(COLOR_PAIR(7));//deja de aplicar color
     for(it = snakes.begin(); it != snakes.end(); it++) {
      init_pair(1,COLOR_GREEN,COLOR_RED);
        attron(COLOR_PAIR(1));
        attron(COLOR_PAIR(1));//aplica color
      mvaddch((*it).getY(),(*it).getX(),'o');
      attroff(COLOR_PAIR(1));
        attroff(COLOR_PAIR(1));//deja de aplicar color
      if((*it).getY() == y && (*it).getX() == x && it != snakes.begin()) // colision con los bordes
       salir = true;
       if (puntos==100)
        salir = true;
     }
     mvprintw(22, 4, "para ganar debe llegar a los 100 puntos\n", puntos);
     mvprintw(23, 12, "Tu puntaje es %i\n", puntos);
     mvprintw(24, 12, "'p' para salir\n" );
     refresh();
    }

    timeout(-1);
    erase();
    if (puntos==100)
    mvprintw(0, 3, "Fin, ha ganado el juego\n", puntos);
    else
    mvprintw(0, 3, "Fin, sacaste un total de %i puntos.\n", puntos);
    refresh();
    getch(); // esperar la salida(perder o que se retire)

 endwin();
 return 0;
}
