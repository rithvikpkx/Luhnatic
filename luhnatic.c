#include "luhnatic.h"

#include <stdio.h>
#include <string.h>

#define VALID (1)
#define INVALID (0)
#define BAD_INPUT (-1)

int validate(char *num_str) {
    if (!num_str) {
        return BAD_INPUT;
    }

    int len = strlen(num_str);
    if (len == 0) {
        return BAD_INPUT;
    }

    int sum = 0;
    int double_digit = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (num_str[i] < '0' || num_str[i] > '9') {
            return BAD_INPUT;
        }

        int digit = num_str[i] - '0';

        if (double_digit) {
            int doubled = digit * 2;

            if (doubled > 9) {
                sum += doubled % 10;
                doubled /= 10;
                sum += doubled;
            }
            else {
                sum += doubled;
            }

            double_digit = 0;
        }
        else {
            sum += digit;
            double_digit = 1;
        }
    }

    if (sum % 10 == 0) {
        return VALID;
    }
    else {
        return INVALID;
    }
}

// TODO Change implementation to be friendly to interface structure
char *explain(char *num_str) {
    return num_str;
    /*
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

    int valid_num = validate(og_num);

    if (valid_num) {
        printf("---VALID LUHN NUM: %ld---\n", og_num);
    }
    else {
        printf("---INVALID LUHN NUM: %ld---\n", og_num);
    }
    */
}

// TODO implement
long generate(int len) {
    return len;
}

