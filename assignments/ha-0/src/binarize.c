#include "binarize.h"

char *binarize_unsigned(unsigned long long x) {

    // If exceeds max possible value, say about overflow and exit
    if (x > ((INT64_MAX << 1) + 1)) {
        return ("Overflow\n");
    }

    unsigned long long temp;    // Temporary variable for division result

    // Set number of bit blocks based on input value
    unsigned int bound = x > INT64_MAX ? 128 : x > INT32_MAX ? 64 : x > INT16_MAX ? 32 : x > INT8_MAX ? 16 : 8;

    char *result = ALLOCATE(bound + 1);

    // Leading sign zero
    result[0] = '0';

    // Start division
    for (int i = bound - 1; i > 0; i--) {
        temp = x >> (i - 1);
        result[bound - i] = (temp & 1 ? '1' : '0');
    }

    result[bound] = '\0';
    return result;
}

char *binarize_signed(signed long long x) {

    // Check for overflow
    signed long long modulo = llabs(x);
    if (modulo > INT64_MAX) {
        return ("Overflow\n");
    }

    // No need to perform more complex algorithm to positive numbers
    if (x >= 0) {
        return binarize_unsigned(x);
    }

    // Set up sign bit
    unsigned int sign = x >= 0 ? 0 : 1;

    // Set up bound for number
    unsigned int bound = modulo > INT32_MAX ? 64 : modulo > INT16_MAX ? 32 : modulo > INT8_MAX ? 16 : 8;
    char *result = ALLOCATE(bound + 1);
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

    binary[bound - 1] = sign;
    for (int i = 0; i < bound; ++i) {
        result[i] = (binary[bound - i - 1] == 0 ? '0' : '1');
    }
    result[bound] = '\0';
    return result;
}

