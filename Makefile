CC=gcc

main: main.o getch.o execute.o menu.o
	$(CC) main.o getch.o execute.o menu.o -o shell

main.o: main.c
	$(CC) -c main.c -o main.o

getch.o: getch.c
	$(CC) -c getch.c -o getch.o

execute.o: execute.c
	$(CC) -c execute.c -o execute.o

menu.o: menu.c
	$(CC) -c menu.c -o menu.o

clean:
	rm -f *.o shell
