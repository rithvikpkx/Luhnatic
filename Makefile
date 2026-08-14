CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Werror -g

all: luhnatic

luhnatic: cli_main.o luhnatic.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c luhnatic.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f luhnatic *.o
