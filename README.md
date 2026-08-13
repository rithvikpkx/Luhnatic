# Luhnatic
Luhnatic is a small C project for exploring the **Luhn algorithm**, which is used to validate credit card numbers. I built it as a simple way to understand how the algorithm works and play around with generating and validating test card numbers.

## Resources

[Luhn's Algorithm](https://stripe.com/en-it/resources/more/how-to-use-the-luhn-algorithm-a-guide-in-applications-for-businesses)

## Functionality / Usage

Luhnatic is a small CLI written in C.

The CLI has three basic operations:

- `validate` --> checks whether the passed in number satisfies the Luhn checksum
- `generate` --> generates a number of the given length with valid Luhn digits
- `explain` --> shows how the checksum is calculated for a given number in detail

