CC=gcc

main: main.o getch.o execute.o menu.o shell.o history.o
	$(CC) main.o getch.o execute.o menu.o shell.o history.o -o shell

main.o: main.c
	$(CC) -c main.c -o main.o

getch.o: getch.c
	$(CC) -c getch.c -o getch.o

execute.o: execute.c
	$(CC) -c execute.c -o execute.o

menu.o: menu.c
	$(CC) -c menu.c -o menu.o

shell.o: shell.c
	$(CC) -c shell.c -o shell.o

history.o: history.c
	$(CC) -c history.c -o history.o

clean:
	rm -f *.o shell \#* *~
