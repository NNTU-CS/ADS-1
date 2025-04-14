// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t number) {
    uint64_t highest = number;

    while (number != 1) {
        if (number > highest) {
            highest = number;
        }

        if (number % 2 == 0) {
            number /= 2;
        } else {
            number = number * 3 + 1;
        }
    }

    return highest;
}

unsigned int collatzLen(uint64_t value) {
    unsigned int count = 1;

    while (value != 1) {
        if (value % 2 == 0) {
            value /= 2;
        } else {
            value = value * 3 + 1;
        }
        ++count;
    }

    return count;
}

unsigned int seqCollatz(
    unsigned int* outLength,
    uint64_t from,
    uint64_t to
) {
    unsigned int result = 0;
    *outLength = 0;

    for (uint64_t i = from; i <= to; ++i) {
        unsigned int length = collatzLen(i);

        if (length > *outLength) {
            *outLength = length;
            result = static_cast<unsigned int>(i);
        }
    }

    return result;
}
