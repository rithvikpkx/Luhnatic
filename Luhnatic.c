#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BAD_CLI_INVOCATION (1)

long validate_num(long num) {
    return num;
}

int main (int argv, char *argc[]) {
    if (argv <= 2 || argv > 3) {
        printf("USAGE:\n\
                ./Luhnatic validate <16 digit num>\n\
                ./Luhnatic generate <length>\n\
                ./Luhnatic explain <16 digit num>\n");

        return BAD_CLI_INVOCATION;
    }

    if (strcmp(argc[1], "validate") == 0) {
        printf("validate branch\n");

        printf("Parsed Num: %ld\n", strtol(argc[2], NULL, 10));
    }
    else if (strcmp(argc[1], "generate") == 0) {
        printf("generate branch\n");
    }
    else if (strcmp(argc[1], "explain") == 0) {
        printf("explain branch\n");
    }
    else {
        printf("USAGE:\n\
                ./Luhnatic validate <16 digit num>\n\
                ./Luhnatic generate <length>\n\
                ./Luhnatic explain <16 digit num>\n");

        return BAD_CLI_INVOCATION;
    }

    return 0;
}
