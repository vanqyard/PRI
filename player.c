#include "player.h"

#define STARTX 1
#define STARTY 2

int players_shot(int **tab, int **tab2, WINDOW *local_win, int n) {
	
	int ch;
	int starty=STARTX;
	int startx=STARTY;
	
	mvwaddch(local_win,starty,startx-1,'>');
	mvwaddch(local_win,starty,startx+1,'<');
	wrefresh(local_win);
	
	while((ch = getch()) != EOF) {	
		switch(ch) {	
			case KEY_LEFT:
				if (rtomx(startx)!=STARTX) {
					
					mvwaddch(local_win,starty,startx-1,' ');
					mvwaddch(local_win,starty,startx+1,' ');
					startx = startx - step_left_right;
					mvwaddch(local_win,starty,startx-1,'>');
					mvwaddch(local_win,starty,startx+1,'<'); 
					wrefresh(local_win);
					
					break;
				}
			case KEY_RIGHT:
				if (rtomx(startx)!=n) {
					
					mvwaddch(local_win,starty,startx-1,' ');
					mvwaddch(local_win,starty,startx+1,' ');
					startx = startx + step_left_right;
					mvwaddch(local_win,starty,startx-1,'>');
					mvwaddch(local_win,starty,startx+1,'<');   
					wrefresh(local_win);
		
					break;
				}
			case KEY_UP:
				if (rtomy(starty)!=STARTY) {
					
					mvwaddch(local_win,starty,startx-1,' ');
					mvwaddch(local_win,starty,startx+1,' ');
					starty = starty - step_up_down;
					mvwaddch(local_win,starty,startx-1,'>');
					mvwaddch(local_win,starty,startx+1,'<');   
					wrefresh(local_win);
					
					break;
				}
			case KEY_DOWN:
				if (rtomy(starty)!=n) {
					
					mvwaddch(local_win,starty,startx-1,' ');
					mvwaddch(local_win,starty,startx+1,' ');
					starty = starty + step_up_down;
					mvwaddch(local_win,starty,startx-1,'>');
					mvwaddch(local_win,starty,startx+1,'<');  
					wrefresh(local_win);
				
					break;	
				}
			default:
					
				break;
		}
	}
	
	return -1;
}
