
#include "binarize.h"

int main() {

    binarize_unsigned(9223372036854775807);
    binarize_unsigned(9223372036854775808);

    binarize_unsigned(18446744073709551615);

    binarize_signed(-9223372036854775804);

    binarize_unsigned(1608637542);
    binarize_signed(-1608637542);

    printf("----------------------------\n");


    binarize_unsigned_optimized(9223372036854775807);
    binarize_unsigned_optimized(9223372036854775808);

    binarize_unsigned_optimized(18446744073709551615);

    binarize_signed_optimized(-9223372036854775804);

    binarize_unsigned_optimized(1608637542);
    binarize_signed_optimized(-1608637542);

    return 0;
}
