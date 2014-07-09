#include "game.h"

int battle_PvP(int n) {

	WINDOW *mywin;

	initscr();
    cbreak();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	curs_set(0);

	mywin=create_newwin(5, 5, n);
	
	players_shot(NULL, NULL, mywin, n);
	
	//box(mywin,0,0);
	//mvwaddch(mywin,1,1,ACS_HLINE);
	
	wrefresh(mywin);

	wgetch(mywin);

	endwin();
	curs_set(1);
	
	beep();	

	return OK;	
}

int battle_PvC(int n) {

	WINDOW *mywin;

	initscr();
    cbreak();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	curs_set(0);

	mywin=create_newwin(5, 5, n);
	//box(mywin,0,0);
	//mvwaddch(mywin,1,1,ACS_HLINE);
	wrefresh(mywin);

	wgetch(mywin);

	endwin();
	curs_set(1);
	
	beep();	

	return OK;	
}

int load_game(int n) {
	return OK;	
}

int exit_game(int n) {
	return OK;	
}

// Creating new window
WINDOW *create_newwin(int starty_main, int startx_main, int n) {
	
	WINDOW *local_win;
	int i=0, j=0;
	
	int height 	= step_up_down 		* n + 1;
	int width 	= step_left_right 	* n + 1;
	int leap_up_down 	= 2;
	int leap_left_right = 4;

	local_win = newwin(height, width, starty_main, startx_main);
	//box(local_win, 0 , 0);
	
	mvwaddch(local_win, 0, 0, ACS_ULCORNER);
	mvwaddch(local_win, 0, width-1, ACS_URCORNER);
	mvwaddch(local_win, height-1, 0, ACS_LLCORNER);
	mvwaddch(local_win, height-1, width-1, ACS_LRCORNER);

	// left border
	for (j=1 ; j<(step_up_down*n) ; j++) {
		if ( j%leap_up_down ) {
			mvwaddch(local_win,j,0,ACS_VLINE);
		}
		else {
			mvwaddch(local_win,j,0,ACS_LTEE);
		}
	}

	// right border
	for (j=1 ; j<(step_up_down*n) ; j++) {
		if ( j%leap_up_down ) {
			mvwaddch(local_win,j,step_left_right*n,ACS_VLINE);
		}
		else {
			mvwaddch(local_win,j,step_left_right*n,ACS_RTEE);
		}
	}

	// top border
	for (i=1 ; i<(step_left_right*n) ; i++) {
		if ( i%leap_left_right ) {
			mvwaddch(local_win,0,i,ACS_HLINE);
		}
		else {
			mvwaddch(local_win,0,i,ACS_TTEE);
		}
	}

	// bottom border
	for (i=1 ; i<(step_left_right*n) ; i++) {
		if ( i%leap_left_right ) {
			mvwaddch(local_win,step_up_down*n,i,ACS_HLINE);
		}
		else {
			mvwaddch(local_win,step_up_down*n,i,ACS_BTEE);
		}
	}

	// content
	for (j=1 ; j<(step_up_down*n) ; j++) {
		for (i=2 ; i<(step_left_right*n)-1 ; i++) {
			if( (i%leap_left_right) )
				mvwaddch(local_win,j,i,ACS_HLINE);
			
			if( (j%leap_up_down) )
				mvwaddch(local_win,j,i,ACS_VLINE);

			if( (j%leap_up_down)!=0 && (i%leap_left_right)!=0 )
				mvwaddch(local_win,j,i,' ');
		}
	}

	wrefresh(local_win);

	return local_win;
}

// Checking if currently toggled ship had some horizontal neightbours
bool check_if_around_pos_horizont(int **tab, int starty, int startx, int size) {
	int i;
	bool STATE = FALSE;
	
	for (i=0 ; i<size ; i++) {

		if (tab[starty][startx + i]==2) {
			STATE=TRUE;
		}
	}
	
	return STATE;
}

// Checking if currently toggled ship had some vertical neightbours
bool check_if_around_pos_vertical(int **tab, int starty, int startx, int size) {
	int i;
	int STATE = TRUE;
	
	for (i=0 ; i<size ; i++) {

		if (tab[starty +i][startx]==2) {
			STATE=TRUE;
		}
	}
	
	return STATE;
}

// Destroying window
void destroy_win(WINDOW *local_win, int n) {	
	int i, j;
	
	for (j=1 ; j<2*n ; j++) {
	
			if ((j%2) == 0) {
			
				for (i=1 ; i<4*n ; i++) {
				
						mvwaddch(local_win,j,i,' ');
						mvwaddch(local_win,j,i,' ');
						mvwaddch(local_win,j,i,' ');
						mvwaddch(local_win,j,i,' ');
					}
			}

			else {
			
				for (i=0 ; i<4*n ; i++) {
	
					if ((i%4) == 0) {
						mvwaddch(local_win,j,i,' ');
					}				
					else {
						mvwaddch(local_win,j,i,' ');
					}			
				}
			}		
	}
	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
