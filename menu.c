#include "menu.h"

char *choices[] = {
                        
		"PvP",
        "PvC",
        "Load Game",
        "Exit",
        (char *)NULL,

};

int menu() {
	
	ITEM **my_items;
	MENU *my_menu;
    WINDOW *my_menu_win;
 	int n_choices;
	int i, c, k=1;
	int (*function)(int);
	
	// Initialize curses
	initscr();
    cbreak();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	curs_set(0);

	/* ncurses calls */
	
	// Create items 
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));        
	for(i = 0; i < n_choices; ++i) {
    	my_items[i] = new_item(choices[i], NULL);	
	}

	// Crate menu
	my_menu = new_menu((ITEM **)my_items);

	// Create the window to be associated with the menu
    my_menu_win = newwin(10, 40, 4, 4);
    keypad(my_menu_win, TRUE);
		
	// Set main window and sub window
	set_menu_win(my_menu, my_menu_win);
	set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

	// Set menu mark to the string " * "
    set_menu_mark(my_menu, "*");
	
	refresh();

	// Post the menu
	post_menu(my_menu);
	wrefresh(my_menu_win);

	while( (c = wgetch(my_menu_win)) != KEY_F(1) ) {
		switch(c) {
			
			// strzałka w dół
			case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				k<4 ? k++ : 4 ;
				
				break;
			
			// strzałka w górę
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				k>1 ? k-- : 1 ;
				
				break;			

			// Enter
			case 10: {
	
				unpost_menu(my_menu);
       			free_menu(my_menu);
        		
				for(i = 0; i < n_choices; ++i) {
             		free_item(my_items[i]);
				}
				
				
				switch(k) {
					case 1 : 		
						function = battle_PvP; 
						break;
					case 2: 		
						function = battle_PvC; 
						break;
					case 3:
						function = load_game; 
						break;
					case 4:	
						function = exit_game; 
						break;
				}
				
				
				//function = battle_PvP;
				
				delwin(my_menu_win);
				endwin();

				return function(10);
			}			
		}
	}
	
	// in case of F1
	delwin(my_menu_win);
	endwin();
	curs_set(1);
	
	// watch out - real return is higher !
	return function(10);
}

char *level[] = {
                        
		"Easy",
        "Medium",
        "Hard",
        "Back",
        (char *)NULL,

};

char *board[] = {
                        
		"Normal",
        "Torus",
        "Play",
        (char *)NULL,

};
