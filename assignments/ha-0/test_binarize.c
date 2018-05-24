
#include "binarize.h"

int main() {

    binarize_unsigned(9223372036854775807);
    binarize_unsigned(9223372036854775808);

    binarize_unsigned(18446744073709551615);

    binarize_signed(-9223372036854775804);

    unsigned long ul = 1608637542;
    signed long sl = -1608637542;
    binarize_unsigned(ul);
    binarize_signed(sl);

    return 0;
}
