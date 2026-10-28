#include "luhnatic.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
      } else {
        sum += doubled;
      }

      double_digit = 0;
    } else {
      sum += digit;
      double_digit = 1;
    }
  }

  if (sum % 10 == 0) {
    return VALID;
  } else {
    return INVALID;
  }
}

int explain(char *num_str, FILE *fp, bool *is_valid) {
  if (!num_str || !fp) {
    return BAD_INPUT;
  }

  int len = strlen(num_str);
  if (len == 0) {
    return BAD_INPUT;
  }

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
        fprintf(fp,
                "Multi Digit Product: digit product(%d). Sum the individual "
                "digits.\n",
                doubled);

        int digit_sum = 0;

        digit_sum += doubled % 10;
        doubled /= 10;
        digit_sum += doubled;

        fprintf(fp, "Summed digits: %d\n", digit_sum);

        fprintf(fp, "Add to sum: sum(%d) = sum(%d) + summed digits(%d)\n", sum + digit_sum, sum,
                digit_sum);

        sum += digit_sum;
      } else {
        fprintf(fp, "Single Digit Product\n");
        fprintf(fp, "Add to sum: sum(%d) = sum(%d) + summed digits(%d)\n", sum + doubled, sum,
                doubled);

        sum += doubled;
      }

      double_digit = 0;
    } else {
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
    if (is_valid) {
      *is_valid = true;
    }
  } else {
    fprintf(fp, "sum(%d) %% 10 != 0\n", sum);
    fprintf(fp, "INVALID LUHN NUMBER\n");
    if (is_valid) {
      *is_valid = false;
    }
  }

  return SUCCESS;
}

// TODO: implement
int generate(long len, FILE *fp) {
  srand(time(NULL));

  int *digit_arr = calloc((size_t)len, sizeof(int));

  int running_sum = 0;
  int double_digit = 1;

  for (int i = len - 2; i >= 0; i--) {
    int random_digit = rand() % 10;
    digit_arr[i] = random_digit;

    if (double_digit) {
      int doubled = random_digit * 2;

      if (doubled > 9) {
        running_sum += doubled % 10;
        running_sum += doubled / 10;
      } else {
        running_sum += doubled;
      }

      double_digit = 0;
    } else {
      running_sum += random_digit;
      double_digit = 1;
    }
  }

  digit_arr[len - 1] = 10 - running_sum % 10;

  for (int i = 0; i < len; i++) {
    fprintf(fp, "%d", digit_arr[i]);
  }
  fprintf(fp, "\n");

  return SUCCESS;
}
