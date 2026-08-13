CFLAGS = -Werror -Wall -Wextra -Wpedantic -std=c17

Luhnatic: Luhnatic.c
	gcc $(CFLAGS) $^ -o $@

