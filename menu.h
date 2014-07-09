#ifndef MENU_H
#define MENU_H

#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 		4

int menu();
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int battle_PvP(int n);
int battle_PvC(int n);
int load_game(int n);
int exit_game(int n);

#endif
