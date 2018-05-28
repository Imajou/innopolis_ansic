#ifndef INNOPOLIS_ANSIC_BINARIZE_H
#define INNOPOLIS_ANSIC_BINARIZE_H

#include <stdlib.h>
#include <printf.h>

#ifndef ALLOCATE
#define ALLOCATE(i)(malloc((i) * sizeof(char)))
#endif

char *binarize_unsigned(unsigned long long x);

char *binarize_signed(signed long long x);

#endif //INNOPOLIS_ANSIC_BINARIZE_H