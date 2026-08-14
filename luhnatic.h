#ifndef LUHNATIC_H
#define LUHNATIC_H

#include <stdio.h>

// Function Declarations

/**
 * Validates a number against Luhn's Algorithm.
 * Digits are processed right to left. Every second digit is doubled,
 * and doubled products that are two digits have the sum of those digits summed.
 *
 * The number is valid if the resulting sum of digits is divisible by 10.
 *
 * @brief Validates the given num string using Luhn's Algorithm
 *
 * @param num_str String of num to be validated
 * @return 1 if valid Luhn num, 0 if invalid Luhn num, and -1 if bad input string @p num_string
 */
int validate(char *num_str);

/**
 * Generates a valid Luhn number of the desired length.
 * Uses random numbers so same size doesn't always generate same number.
 *
 * @brief Randomly generates valid Luhn number of desired size
 * @param len The length of the desired valid Luhn number
 * @return A valid luhn number of length @p len
 */
long generate(int len);

/**
 * Writes the full explanation/process of Luhn's Algorithm given a num string to a file.
 *
 * @param num_str String of num to be validated
 * @return 0 on success, 1 on failure, -1 on bad input
 */
int explain(char *num_str, FILE *fp);

#endif
