#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>

/* (r)eal - to wartość dla kursora, 
 * (m)emory - to wartość w pamięci*/
#define rtomx(x) (((x+2)/4))
#define rtomy(y) (((y+1)/2))
#define mtorx(x) (4*(x)-2)
#define mtory(y) (2*(y)-1)

int step_up_down;
int step_left_right;

int players_shot(int **tab, int **tab2, WINDOW *local_win, int n);

#endif // PLAYER_H
