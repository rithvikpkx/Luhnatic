#ifndef LUHNATIC_H
#define LUHNATIC_H

// Function Declarations

/**
 * Validates a number against Luhn's Algorithm.
 * Digits are processed right to left. Every second digit is doubled,
 * and doubled products that are two digits have the sum of those digits summed.
 *
 * The number is valid if the resulting sum of digits is divisible by 10.
 *
 * @brief Validates the given num using Luhn's Algorithm
 *
 * @param num The num to be validated
 * @return 1 if valid Luhn num or 0 if invalid Luhn num.
 */
int validate(long num);

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
 * Prints out the full process of Luhn's Algorithm given a number to explain it.
 *
 * @param num The num to be validated and explained.
 */

void explain(long num);

#endif
