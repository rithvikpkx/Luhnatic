#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BAD_CLI_INVOCATION (1)
#define SUCCESS (0)

int validate_num(long num) {
    int sum = 0;

    int sum_digit = 0;

    while (num) {
        if (sum_digit == 0) {
            sum += num % 10;
            num /= 10;
            sum_digit = 1;
        }
        else {
            int doubled = (num % 10) * 2;

            if (doubled > 9) {
                sum += doubled % 10;
                doubled /= 10;
                sum += doubled;
            }
            else {
                sum += doubled;
            }

            sum_digit = 0;
            num /= 10;
        }
    }

    if (sum % 10 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main (int argv, char *argc[]) {
    if (argv <= 2 || argv > 3) {
        printf("USAGE:\n\
                ./Luhnatic validate <num>\n\
                ./Luhnatic generate <length>\n\
                ./Luhnatic explain <num>\n");

        return BAD_CLI_INVOCATION;
    }

    if (strcmp(argc[1], "validate") == 0) {
        char *endptr = NULL;
        long num = strtol(argc[2], &endptr, 10);

        if (endptr == argc[2] || *endptr != '\0') {
            printf("INVALID\n");
            printf("USAGE: ./Luhnatic validate <num>\n");
            return BAD_CLI_INVOCATION;
        }
        else {
            int valid_num = validate_num(num);

            if (valid_num) {
                printf("---VALID LUHN NUM: %ld---\n", num);
            }
            else {
                printf("---INVALID LUHN NUM: %ld---\n", num);
            }
        }
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

    return SUCCESS;
}
