#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int main(int argc, char **argv) {
    WINDOW *w;

    iniciarVentana(w);
    cerrarVentana(w);

    return 0;
}