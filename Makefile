a.out : main.o menu.o game.o player.o constants.h
	gcc main.o menu.o game.o player.o -o a.out -lncurses -lmenu -O2 -ansi -Wall -m486

main.o : main.c main.h
	gcc -c main.c -o main.o

menu.o : menu.c menu.h
	gcc -c menu.c -o menu.o

game.o : game.c game.h
	gcc -c game.c -o game.o

player.o : player.c player.h
	gcc -c player.c -o player.o 
	
clean:
	rm player.o
	rm main.o
	rm menu.o
	rm game.o
	rm a.out
