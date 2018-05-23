#include "binarize.h"

void binarize_unsigned(unsigned long long x) {

    // If exceeds max possible value, say about overflow and exit
    if (x > (INT64_MAX)) {
        printf("Overflow");
        return;
    }

    unsigned long long temp;    // Temporary variable for division result
    unsigned short sep = 1;     // Space separator counter

    // Set number of bit blocks based on input value
    unsigned int boundary = x > INT32_MAX ? 62 : x > INT16_MAX ? 30 : x > INT8_MAX ? 14 : 6;

    // Leading sign zero
    printf("0");

    // Start division
    for (int i = boundary; i >= 0; i--) {
        temp = x >> i;

        if (temp & 1)
            printf("1");
        else
            printf("0");

        // Separator update
        ++sep;
        if (sep == 8) {
            printf(" ");
            sep = 0;
        }
    }

    // New line
    printf("\n");
}

void binarize_signed(signed long long x) {
    if (x >= 0) {
        binarize_unsigned(x);
        return;
    }
}