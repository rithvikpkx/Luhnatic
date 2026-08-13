# Luhnatic
> Luhnatic is a small C project for exploring the **Luhn algorithm**, which is used to validate credit card numbers. I built it as a simple way to understand how the algorithm works and play around with generating and validating test card numbers.


## Topics

`C` · `Luhn Algorithm` · `Checksums` · `CLI` · `Input Validation` · `String Processing` · `Modular Arithmetic` · `Command-Line Tools`

[Luhn's Algorithm Stripe Article](https://stripe.com/en-it/resources/more/how-to-use-the-luhn-algorithm-a-guide-in-applications-for-businesses)

## Functionality / Usage

Luhnatic is a small CLI written in C.

The CLI has three basic operations:

- `validate` --> checks whether the passed in number satisfies the Luhn checksum
    ```bash
    $ ./Luhnatic validate 79927398713
    ---VALID LUHN NUM: 79927398713---

    $ ./Luhnatic validate 4552720412345678
    ---INVALID LUHN NUM: 4552720412345678---
    ```

- `generate` --> generates a number of the given length with valid Luhn digits

- `explain` --> shows how the checksum is calculated for a given number in detail

> [!QUESTION]
> Why did I build this?
> 
> Whenever I typed in a random number into credit card fields, I always wondered how they were able to immediately invalidate it.
> After a bit of research I found out about Luhn's Algorithm and I wanted to build a cool little tool for fun.
> So, in short, for fun!


