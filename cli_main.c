#include "luhnatic.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VALID (0)
#define INVALID (1)
#define GENERATED (2)
#define EXPLAINED (3)
#define BAD_CLI_INVOCATION (-1)

enum command {
    CMD_VALIDATE,
    CMD_GENERATE,
    CMD_EXPLAIN,
    CMD_INVALID
};

struct command_info {
    enum command command;
    const char *name;
    const char *arg;
};

static const struct command_info COMMANDS[] = {
    {CMD_VALIDATE, "validate", "<number>"},
    {CMD_GENERATE, "generate", "<length>"},
    {CMD_EXPLAIN, "explain", "<number>"}
};

static enum command parse_arg(char *arg) {
    for (size_t i = 0; i < sizeof(COMMANDS) / sizeof(COMMANDS[0]); i++) {
        if (strcmp(arg, COMMANDS[i].name) == 0) {
            return COMMANDS[i].command;
        }
    }

    return CMD_INVALID;
}

static void print_usage(void) {
    printf("USAGE:\n");

    for (size_t i = 0; i < sizeof(COMMANDS) / sizeof(COMMANDS[0]); i++) {
        printf("    luhnatic %s %s\n", COMMANDS[i].name, COMMANDS[i].arg);
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 2 || argc > 3) {
        print_usage();
        return BAD_CLI_INVOCATION;
    }

    // TODO change parsing logic
    char *endptr = NULL;
    long num = strtol(argv[2], &endptr, 10);

    if (endptr == argv[2] || *endptr != '\0') {
        printf("INVALID ARGUMENT\n");
        print_usage();
        return BAD_CLI_INVOCATION;
    }

    enum command command = parse_arg(argv[1]);

    if (command == CMD_INVALID) {
        printf("INVALID COMMAND\n");
        print_usage();
        return BAD_CLI_INVOCATION;
    }
    else {
        if (command == CMD_VALIDATE) {
            int valid = validate(num);

            if (valid) {
                printf("VALID LUHN NUM: %ld\n", num);
                return VALID;
            }
            else {
                printf("INVALID LUHN NUM: %ld\n", num);
                return INVALID;
            }
        }
        else if (command == CMD_GENERATE) {
            long generated_num = generate(num);
            printf("GENERATED LUHN NUM: %ld\n", generated_num);
            return GENERATED;
        }
        else if (command == CMD_EXPLAIN) {
            explain(num);
            return EXPLAINED;
        }
    }
}
