all: snake main clean

snake: snake.c
		gcc -c snake.c -lncurses
main: snake.o main.c 
		gcc snake.o main.c -o snake -lncurses
clean:
	rm -f *.o
