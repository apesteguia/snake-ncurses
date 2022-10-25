#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>
#include "snake.h"

char *titulo = "Snake Game";

void iniciarVentana(WINDOW *win) {
    int x, y, start_y, start_x, i, j;
    char c,d;
    char snake[DIMS];
    bool b = true;

    snake[0] = '*';
    
    i = 25;
    j = 25;

    initscr();
    getmaxyx(stdscr, y, x);
    cbreak();
    noecho();
    start_y = (y-WDIMY)/2;
    start_x = (x-WDIMX)/2;
    win = newwin(WDIMY, WDIMX, start_y, start_x);
    box(win, 0, 0);
    start_color();
    curs_set(0);
    
    keypad(win, true);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    wbkgd(win, COLOR_PAIR(2));

    mvwprintw(win,0,11,titulo);

    c = wgetch(win);
    wrefresh(win);
    do
    {
        d = movimiento(win, c, snake, &i, &j, strlen(snake));
        wrefresh(win);
        //c = wgetch(win);
        c = d;
    } while (d != 'q');
    
    wrefresh(win);
    c = d; 
}

char movimiento(WINDOW *win, char c, char snake[DIMS], int *h, int *w, int k) {
    char d = ' ';
    char *e;
    int i,j,f,m;
    i = *h;
    j = *w;
    if (c == 'd') {
        while (1)
        {
            nodelay(win, true);
            wclear(win);
            wrefresh(win);
            box(win, 0, 0);
            mvwprintw(win,0,11,titulo);
            mvwprintw(win, j, i+1, snake);
            i = i + 2;
            wrefresh(win);
            usleep(500000);
            d = wgetch(win);
            if (d == 'f' || d == 'w' || d == 's' || d == 'a') {
                *h = i;
                *w = j;
                return d;
            }
            nodelay(win, false);
        }
        }
         
    else if (c == 'a') {
        while (1) {
            nodelay(win, true);
            wclear(win);
            wrefresh(win);
            box(win, 0, 0);
            mvwprintw(win, j, i-1, snake);
            mvwprintw(win,0,11,titulo);
            i = i - 2;
            wrefresh(win);
            usleep(500000);
            d = wgetch(win);
            if (d == 'f' || d == 'w' || d == 's' || d == 'd') {
                *h = i;
                *w = j;
                return d;
            }
            nodelay(win, false);
        }
    }

    else if (c == 'w') {
        while (1) {
            nodelay(win, true);
            wclear(win);
            wrefresh(win);
            box(win, 0, 0);
            mvwprintw(win,0,11,titulo);
            m = j;
            for (f=0; f<k; f++) {
                mvwaddch(win, j-1, i, snake[f]);
                j--;
            }
            m--;
            wrefresh(win);
            usleep(900000);
            d = wgetch(win);
            if (d == 'f' || d == 'd' || d == 's' || d == 'a') {
                *h = i;
                *w = j;
                return d;
            }
            nodelay(win, false);
        }
    }
    else if (c == 's') {
        while (1) {
            nodelay(win, true);
            wclear(win);
            wrefresh(win);
            box(win, 0, 0);
            mvwprintw(win,0,11,titulo);
            m = j;
            for (f=0; f<k;f++) {
                mvwaddch(win, j+1, i, snake[f]);
                j++;
            }
            m++;
            wrefresh(win);
            usleep(900000);
            d = wgetch(win);
            if (d == 'f' || d == 'w' || d == 'd' || d == 'a') {
                *h = i;
                *w = j;
                return d;
            }
            nodelay(win, false);
            }
    }
    *h = i;
    *w = j;
    return d;
}

void cerrarVentana(WINDOW *win) {
    delwin(win);
    endwin();
}


/*
nodelay(win, true);
            wclear(win);
            wrefresh(win);
            box(win, 0, 0);
            mvwprintw(win,0,11,titulo);
            mvwprintw(win, j-1, i, snake);
            j--;
            wrefresh(win);
            sleep(1);
            d = wgetch(win);
            if (d == 'f') {
                *h = i;
                *w = j;
                return d;
            }
            nodelay(win, false);
*/