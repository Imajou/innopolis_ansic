#include "bitMap.h"

#define LENGTH 32

/**
 * Sets {@param bit} with {@param position} in pointer {@param array}
 * @param array Pointer
 * @param bit Bit to set
 * @param position Position of a bit
 */
void setBitByNumber(int *array, int bit, int position) {
    if (array == NULL) {
        printf("java.lang.NullPointerException");
        return;
    }
    if ((bit != 1) && (bit != 0)) {
        printf("java.lang.InvalidArgumentException");
        return;
    }
    if (position < 0) {
        printf("java.lang.ArrayIndexOutOfBoundException");
        return;
    }

    int wordIndex = position / LENGTH;
    int bitIndex = position % LENGTH;

    unsigned int word = (unsigned int) array[wordIndex];
    unsigned int shift = (unsigned int) pow(2, LENGTH - bitIndex - 1);

    if (bit == 0) word = word & (0xFFFFFFFF - shift);
    else if ((word & shift) == 0)
        word += shift;

    array[wordIndex] = word;
}

/**
 * Gets bit on {@param position} in pointer {@param array}
 * @param array Pointer
 * @param position Position of a bit
 * @return Needed bit or -INF if error
 */
int getBitByNumber(int *array, int position) {
    if (array == NULL) {
        printf("java.lang.NullPointerException");
        return -INFINITY;
    }
    if (position < 0) {
        printf("java.lang.ArrayIndexOutOfBoundException");
        return -INFINITY;
    }

    unsigned int wordIndex = (unsigned) position / LENGTH;
    unsigned int bitIndex = (unsigned) position % LENGTH;

    unsigned int getMask = (unsigned int) array[wordIndex] & (unsigned int) pow(2, LENGTH - bitIndex - 1);
    unsigned int getBit = getMask >> (LENGTH - bitIndex - 1);

    return getBit;
}

/**
 * Set {@param bit} as the first bit on pointer {@param position}
 * @param position Pointer
 * @param bit Bit to set
 */
void setBitByAddress(void *position, int bit) {
    if (position == NULL) {
        printf("java.lang.NullPointerException");
        return;
    }
    if ((bit != 1) && (bit != 0)) {
        printf("java.lang.InvalidArgumentException");
        return;
    }

    unsigned int *word = (unsigned int *) position;

    if (bit == 0) *word = (*word) & (unsigned int) 0x7FFFFFFF;
    else if (!((*word) & 0x80000000))
        *word += (unsigned int) pow(2, 31);

}

/**
 * Gets the first bit on specified {@param position} pointer
 * @param position Pointer
 * @return Needed bit or -INF if error
 */
int getBitByAddress(void *position) {

    if (position == NULL) {
        printf("java.lang.NullPointerException");
        return -INFINITY;
    }

    unsigned int getMask = (unsigned int) (*(int *) position) & 0x80000000;
    unsigned int getBit = getMask >> (unsigned int) (LENGTH - 1);

    return getBit;
}

/*
int main(){
    int * ptr = malloc(8 * sizeof(int));
    for (int i = 0; i < 8; ++i) {
        ptr[i] = 0;
    }
    for (int j = 0; j < 8; ++j) {
        printf("%d", ptr[j]);
    }
    printf("\n");
    setBitByAddress(ptr, 1);
    for (int j = 0; j < 8; ++j) {
        printf("%d", ptr[j]);
    }
    return 0;
}*/
