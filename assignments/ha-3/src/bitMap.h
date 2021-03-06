#ifndef HA_2_BITMAP_H
#define HA_2_BITMAP_H

#include <math.h>
#include <stdlib.h>
#include <printf.h>

void setBitByNumber(int *array, int bit, int position);

int getBitByNumber(int *array, int position);

void setBitByAddress(void *position, int bit);

int getBitByAddress(void *position);

#endif //HA_2_BITMAP_H
