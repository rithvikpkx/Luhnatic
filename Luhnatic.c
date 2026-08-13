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

void explain(long num) {
    long og_num = num;
    printf("Original Number: %ld\n", og_num);

    printf("Starting from right: ");
    long n_copy = num;
    while (n_copy) {
        printf("%ld ", n_copy % 10);

        n_copy /= 10;
    }
    printf("\n\n");

    int sum = 0;
    int sum_digit = 0;

    printf("Start running sum at 0: sum(0)\n");

    while (num) {
        if (sum_digit == 0) {
            printf("Non doubled digit: %ld\n", num % 10);
            printf("Add digit to sum:  sum(%d) + digit(%ld) = sum(%ld)\n", sum, num % 10, sum + (num % 10));

            sum += num % 10;
            num /= 10;
            sum_digit = 1;
        }
        else {
            printf("To be doubled digit: %ld\n", num % 10);
            int doubled = (num % 10) * 2;
            printf("Doubled digit: %d\n", doubled);
            printf("\n");

            if (doubled > 9) {
                printf("Doubled digit yields a two digit product: %d\n", doubled);

                printf("Add individual digit to sum: sum(%d) + digit(%d) = sum(%d)\n", sum, doubled % 10, sum + (doubled % 10));
                sum += doubled % 10;
                doubled /= 10;
                printf("Add individual digit to sum: sum(%d) + digit(%d) = sum(%d)\n", sum, doubled, sum + doubled);
                sum += doubled;
            }
            else {
                printf("Add doubled digit to sum: sum(%d) + digit(%d) = sum(%d)\n", sum, doubled, sum + doubled);
                sum += doubled;
            }

            sum_digit = 0;
            num /= 10;
        }
        printf("------------------------\n");
    }

    printf("\n");

    if (sum % 10 == 0) {
        printf("sum(%d) %% 10 == 0\n", sum);
    }
    else {
        printf("sum(%d) %% 10 != 0\n", sum);
    }

    int valid_num = validate_num(og_num);

    if (valid_num) {
        printf("---VALID LUHN NUM: %ld---\n", og_num);
    }
    else {
        printf("---INVALID LUHN NUM: %ld---\n", og_num);
    }
}

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
        int valid_num = validate_num(num);

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
