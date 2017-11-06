CC=gcc

all:
	mkdir -p obj bin
	@echo "Created obj bin directory!"

compile:	bin/aqshell

help:
	@echo "make compile   : compile source code"
	@echo "make run       : compiler source code and run"
	@echo "make clean     : delete all obj file and executable file."
	@echo "Before compiler source code, you should create obj bin directory with this command: make all"

bin/aqshell: obj/main.o obj/getch.o obj/execute.o obj/menu.o obj/shell.o obj/history.o obj/parserPipe.o
	$(CC) obj/main.o obj/getch.o obj/execute.o obj/menu.o obj/shell.o obj/history.o obj/parserPipe.o -o bin/aqshell

obj/main.o: src/main.c
	$(CC) -c src/main.c -o obj/main.o

obj/getch.o: src/getch.c
	$(CC) -c src/getch.c -o obj/getch.o

obj/execute.o: src/execute.c
	$(CC) -c src/execute.c -o obj/execute.o

obj/menu.o: src/menu.c
	$(CC) -c src/menu.c -o obj/menu.o

obj/shell.o: src/shell.c
	$(CC) -c src/shell.c -o obj/shell.o

obj/history.o: src/history.c
	$(CC) -c src/history.c -o obj/history.o

obj/parserPipe.o: src/parserPipe.c
	$(CC) -c src/parserPipe.c -o obj/parserPipe.o

run: bin/aqshell
	./bin/aqshell

clean:
	rm -f obj/* bin/aqshell \#* *~