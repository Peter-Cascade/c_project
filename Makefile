CC = gcc

CFLAGS = -Wall -Wextra -g -o0

learn: learn.c
	$(CC) $(CFLAGS) learn.c -o learn

run: learn
	./learn

gdb: learn
	gdb ./learn

memcheck: debug_learn
	valgrind --leak-check=full --show-leak-kinds=all ./learn

clean:
	rm -f learn

.PHONY: run gdb memcheck clean