#include "luhnatic.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAD_CLI_INVOCATION (1)

typedef enum command {
  CMD_VALIDATE,
  CMD_GENERATE,
  CMD_EXPLAIN,
  CMD_INVALID,
} command_t;

struct command_info {
  enum command command;
  const char *name;
  const char *arg;
};

static const struct command_info COMMANDS[] = {
  {CMD_VALIDATE, "validate", "<number>"},
  {CMD_GENERATE, "generate", "<length>"},
  {CMD_EXPLAIN, "explain", "<number>"},
};

static command_t parse_command(char *arg) {
  for (size_t i = 0; i < sizeof(COMMANDS) / sizeof(COMMANDS[0]); i++) {
    if (strcmp(arg, COMMANDS[i].name) == 0) {
      return COMMANDS[i].command;
    }
  }

  return CMD_INVALID;
}

static void print_usage(FILE *fp) {
  fprintf(fp, "USAGE:\n");

  for (size_t i = 0; i < sizeof(COMMANDS) / sizeof(COMMANDS[0]); i++) {
    fprintf(fp, "    luhnatic %s %s\n", COMMANDS[i].name, COMMANDS[i].arg);
  }
}

int main(int argc, char *argv[]) {
  if (argc <= 2 || argc > 3) {
    print_usage(stderr);
    return BAD_CLI_INVOCATION;
  }

  command_t command = parse_command(argv[1]);

  if (command == CMD_INVALID) {
    fprintf(stderr, "INVALID COMMAND\n");
    print_usage(stderr);
    return BAD_CLI_INVOCATION;
  }

  if (command == CMD_VALIDATE) {
    int valid = validate(argv[2]);

    if (valid == VALID) {
      printf("VALID LUHN NUM: %s\n", argv[2]);
    } else if (valid == INVALID) {
      printf("INVALID LUHN NUM: %s\n", argv[2]);
    } else {
      fprintf(stderr, "BAD ARGUMENT\n");
      print_usage(stderr);
      return BAD_CLI_INVOCATION;
    }
  } else if (command == CMD_GENERATE) {
    generate(atoi(argv[2]), stdout);
  } else if (command == CMD_EXPLAIN) {
    int ret_val = explain(argv[2], stdout, NULL /* is_valid not needed */);

    if (ret_val == BAD_INPUT) {
      fprintf(stderr, "BAD ARGUMENT\n");
      print_usage(stderr);
      return BAD_CLI_INVOCATION;
    } else if (ret_val == FAILURE) {
      fprintf(stderr, "FAILURE: Something went wrong with the file stream\n");
      return BAD_CLI_INVOCATION;
    }
  }

  return SUCCESS;
}
