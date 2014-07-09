#ifndef GAME_H
#define GAME_H
#include <ncurses.h>
#include <stdlib.h>
#include "constants.h"

WINDOW *create_newwin(int starty_main, int startx_main, int n);
WINDOW *set_board_player(int height, int width, int starty_main, int startx_main, int **tab, int n);

bool check_if_around_pos_horizont(int **tab, int starty, int startx, int size);
bool check_if_around_pos_vertical(int **tab, int starty, int startx, int size);

void destroy_win(WINDOW *local_win, int n);

int battle_PvP(int n);
int battle_PvC(int n);
int load_game(int n);
int exit_game(int n);
#endif // GAME_H
