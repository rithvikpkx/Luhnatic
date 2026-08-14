#include "luhnatic.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BAD_CLI_INVOCATION (1)
#define SUCCESS (0)

int main (int argc, char *argv[]) {
    if (argc <= 2 || argc > 3) {
        printf("USAGE:\n\
                ./Luhnatic validate <num>\n\
                ./Luhnatic generate <length>\n\
                ./Luhnatic explain <num>\n");

        return BAD_CLI_INVOCATION;
    }

    char *endptr = NULL;
    long num = strtol(argv[2], &endptr, 10);

    if (endptr == argv[2] || *endptr != '\0') {
        printf("INVALID\n");
        printf("USAGE:\n\
                ./Luhnatic validate <num>\n\
                ./Luhnatic generate <length>\n\
                ./Luhnatic explain <num>\n");
        return BAD_CLI_INVOCATION;
    }

    if (strcmp(argv[1], "validate") == 0) {
        int valid_num = validate(num);

        if (valid_num) {
            printf("---VALID LUHN NUM: %ld---\n", num);
        }
        else {
            printf("---INVALID LUHN NUM: %ld---\n", num);
        }
    }
    else if (strcmp(argv[1], "generate") == 0) {
        printf("generate branch\n");
    }
    else if (strcmp(argv[1], "explain") == 0) {
        explain(num);
    }
    else {
        printf("USAGE:\n\
                ./Luhnatic validate <num>\n\
                ./Luhnatic generate <length>\n\
                ./Luhnatic explain <num>\n");

        return BAD_CLI_INVOCATION;
    }

    return SUCCESS;
}
