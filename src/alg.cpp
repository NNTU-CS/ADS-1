#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    
    if (value == 2 || value == 3) {
        return true;
    }
    
    if (value % 2 == 0 || value % 3 == 0) {
        return false;
    }
    
    for (int i = 5; (i * i) <= value; i+=6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t limit = 10000000;
    int count = 0;
    
    for (int i = 0; i <= limit; i++) {
        if (checkPrime(i))
            count++;
        if (count == n)
            return i;
    }
}

uint64_t nextPrime(uint64_t value) {
    if (value <= 1) {
        return 2;
    }

    uint64_t next = value + 1;
    while (true) {
        if (checkPrime(next)) {
            return next;
        }
        next++;
        if (next == 0) {
            return 0;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    
    if (hbound <= 2) {
        return 0;
    }
    
    for (uint64_t i = 3; i <= hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }

    return sum;
    
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (lbound > hbound) return 0;
    if (hbound < 3) return 0;
    
    int count = 0;
    
    while (lbound <= hbound - 2) {
        lbound++;
        if (checkPrime(lbound)) {
            if (!(checkPrime(nextPrime(lbound)))){
                if (checkPrime(nextPrime(nextPrime(lbound)))) {
                    count++;
                }
            }
        }
    }
    
    return count;
}
