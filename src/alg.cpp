// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if ( value <= 1 )
        return false;

    for ( uint64_t k = 2; k <= value / 2; k++ )
        if (value % k == 0)
            return false;

    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t number = 0;
    for ( uint64_t i = 0; i < n; number = nextPrime( number ), ++i ) continue;

    return number;
}

uint64_t nextPrime(uint64_t value) {
    for ( uint64_t i = value + 1; ; ++i )
        if ( checkPrime( i ) )
            return i;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for ( uint64_t i = nextPrime( 0 ); i < hbound; i = nextPrime( i ) )
        sum += i;

    return sum;
}
