#include "luhnatic.h"

#include <stdio.h>
#include <string.h>

#define VALID (1)
#define INVALID (0)
#define BAD_INPUT (-1)

#define SUCCESS (0)
#define FAILURE (1)

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
int explain(char *num_str, FILE *fp) {
    if (!num_str || !fp) {
        return BAD_INPUT;
    }

    int len = strlen(num_str);
    if (len == 0) {
        return BAD_INPUT;
    }

    fwrite("", 1, 0, fp);

    if (ferror(fp)) {
        clearerr(fp);
        return FAILURE;
    }

    for (int i = 0; i < len; i++) {
        if (num_str[i] < '0' || num_str[i] > '9') {
            return BAD_INPUT;
        }
    }

    int sum = 0;

    fprintf(fp, "Number: %s\n", num_str);
    fprintf(fp, "Start running sum at 0: sum(%d)\n", sum);
    fprintf(fp, "Start from the rightmost digit and move leftward\n\n");

    int double_digit = 0;

    for (int i = len - 1; i >= 0; i--) {
        fprintf(fp, "---\n");
        fprintf(fp, "Current Digit: %c\n", num_str[i]);

        int digit = num_str[i] - '0';

        if (double_digit) {
            fprintf(fp, "Double Digit\n");

            int doubled = digit * 2;

            fprintf(fp, "Double: digit(%d) * 2 = %d\n", digit, doubled);

            if (doubled > 9) {
                fprintf(fp, "Multi Digit Product: digit product(%d). Sum the individual digits.\n", doubled);

                int digit_sum = 0;

                digit_sum += doubled % 10;
                doubled /= 10;
                digit_sum += doubled;


                fprintf(fp, "Summed digits: %d\n", digit_sum);

                fprintf(fp, "Add to sum: sum(%d) = sum(%d) + summed digits(%d)\n", sum + digit_sum, sum, digit_sum);

                sum += digit_sum;
            }
            else {
                fprintf(fp, "Single Digit Product\n");
                fprintf(fp, "Add to sum: sum(%d) = sum(%d) + summed digits(%d)\n", sum + doubled, sum, doubled);
                sum += doubled;
            }

            double_digit = 0;
        }
        else {
            fprintf(fp, "Non Double Digit\n");
            fprintf(fp, "Add to sum: sum(%d) = sum(%d) + digit(%d)\n", sum + digit, sum, digit);
            sum += digit;
            double_digit = 1;
        }
    }

    fprintf(fp, "---\n");
    fprintf(fp, "Final Sum: %d\n", sum);

    if (sum % 10 == 0) {
        fprintf(fp, "sum(%d) %% 10 == 0\n", sum);
        fprintf(fp, "VALID LUHN NUMBER\n");
        return VALID;
    }
    else {
        fprintf(fp, "sum(%d) %% 10 != 0\n", sum);
        fprintf(fp, "INVALID LUHN NUMBER\n");
        return INVALID;
    }

}

// TODO implement
long generate(int len) {
    return len;
}

