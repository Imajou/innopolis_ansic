#include "binarize.h"

void binarize_unsigned(unsigned long long x) {

    // If exceeds max possible value, say about overflow and exit
    if (x > ((INT64_MAX << 1) + 1)) {
        printf("Overflow\n");
        return;
    }

    unsigned long long temp;    // Temporary variable for division result
    unsigned short delimiter = 1;     // Space separator counter

    // Set number of bit blocks based on input value
    unsigned int bound = x > INT64_MAX ? 126 : x > INT32_MAX ? 62 : x > INT16_MAX ? 30 : x > INT8_MAX ? 14 : 6;

    // Leading sign zero
    printf("0");

    // Start division
    for (int i = bound; i >= 0; i--) {

        temp = x >> i;
        printf(temp & 1 ? "1" : "0");

        // Check for delimiter to print
        ++delimiter;
        if (delimiter == 8) {
            printf(" ");
            delimiter = 0;
        }
    }

    // New line
    printf("\n");
}

void binarize_signed(signed long long x) {

    // Check for overflow
    signed long long modulo = llabs(x);
    if (modulo > INT64_MAX) {
        printf("Overflow\n");
        return;
    }

    // No need to perform more complex algorithm to positive numbers
    if (x >= 0) {
        binarize_unsigned(x);
        return;
    }

    // Set up sign bit
    unsigned int sign = x >= 0 ? 0 : 1;

    // Set up bound for number
    unsigned int bound = modulo > INT32_MAX ? 64 : modulo > INT16_MAX ? 32 : modulo > INT8_MAX ? 16 : 8;
    unsigned int binary[bound];

    // Convert the modulo to binary in little-endian notation
    for (int i = 0; i < bound - 1; ++i) {
        binary[i] = (unsigned int) x % 2;
        x = x >> 1;
    }

    // Compliment the number
    for (int i = 0; i < bound - 1; ++i) {
        binary[i] = binary[i] == 0 ? 1 : 0;
    }

    // Add 1
    unsigned int carry = 1;     // Carry adder
    for (int i = 0; i < bound - 1; ++i) {
        binary[i] = binary[i] ^ carry;
        carry == binary[i] & carry;
    }

    // Print the number
    unsigned int delimiter = 0;
    binary[bound - 1] = sign;
    for (int i = bound - 1; i >= 0; --i) {

        printf("%i", binary[i]);

        // Check for delimiter to print
        ++delimiter;
        if (delimiter == 8) {
            printf(" ");
            delimiter = 0;
        }
    }

    // New line
    printf("\n");
}

void binarize_unsigned_optimized(unsigned long long x) {

    // Check for overflow
    if (x > ((INT64_MAX << 1) + 1)) {
        printf("Overflow\n");
        return;
    }

    unsigned int bound = x > INT64_MAX ? 127 : x > INT32_MAX ? 63 : x > INT16_MAX ? 31 : x > INT8_MAX ? 15 : 7;
    unsigned short delimiter = 1;
    printf("0");
    for (int i = bound - 1; 0 <= i; --i) {
        if (delimiter == 8) {
            printf(" ");
            delimiter = 0;
        }
        ++delimiter;
        printf("%llx", (x >> i) & 0x01);
    }
    printf("\n");
}

void binarize_signed_optimized(signed long long x) {

    // Check for overflow
    if (x > INT64_MAX) {
        printf("Overflow\n");
        return;
    }

    signed long long modulo = llabs(x);
    unsigned int bound = modulo > INT32_MAX ? 63 : modulo > INT16_MAX ? 31 : modulo > INT8_MAX ? 15 : 7;
    unsigned short delimiter = 1;
    printf(x >= 0 ? "0" : "1");
    for (int i = bound - 1; 0 <= i; --i) {
        if (delimiter == 8) {
            printf(" ");
            delimiter = 0;
        }
        ++delimiter;
        printf("%llx", (x >> i) & 0x01);
    }
    printf("\n");
}