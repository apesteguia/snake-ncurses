#ifndef MIKEL_SNAKE
#define MIKEL_SNAKE

#include <ncurses.h>

#define WDIMX 55
#define WDIMY 35
#define DIMS  10

void iniciarVentana(WINDOW *win);
void cerrarVentana(WINDOW *win);
char movimiento(WINDOW *win, char c, char snake[DIMS], int *i, int *j, int k);

#endif 
