#include "luhnatic.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS (0)
#define BAD_CLI_INVOCATION (-1)

typedef enum command {
    CMD_VALIDATE,
    CMD_GENERATE,
    CMD_EXPLAIN,
    CMD_INVALID
} command_t;

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

static command_t parse_command(char *arg) {
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

    command_t command = parse_command(argv[1]);

    if (command == CMD_INVALID) {
        printf("INVALID COMMAND\n");
        print_usage();
        return BAD_CLI_INVOCATION;
    }

    // TODO change parsing logic to not be limited by long overflow
    char *endptr = NULL;
    long arg = strtol(argv[2], &endptr, 10);

    if (endptr == argv[2] || *endptr != '\0') {
        printf("INVALID ARGUMENT\n");
        print_usage();
        return BAD_CLI_INVOCATION;
    }

    if (command == CMD_VALIDATE) {
        int valid = validate(arg);

        if (valid) {
            printf("VALID LUHN NUM: %ld\n", arg);
        }
        else {
            printf("INVALID LUHN NUM: %ld\n", arg);
        }

    }
    else if (command == CMD_GENERATE) {
        long generated_num = generate(arg);
        printf("GENERATED LUHN NUM: %ld\n", generated_num);
    }
    else if (command == CMD_EXPLAIN) {
        // TODO update implementation to handle new interface handling
        explain(arg);
    }

    return SUCCESS;
}
