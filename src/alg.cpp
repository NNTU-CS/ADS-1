
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if(value < 2){
        return false;
    }

    for (uint64_t i = 2; i <= std::sqrt(value); i++)[
        if (value % i == 0){
            return false;
        }
    ]
  return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t nomer = 0;
    uint64_t chislo = 2;
    while (nomer < n){
        if (checkPrime(chislo)){
            nomer++;
        }
        chislo++;
    }
    return chislo + 1;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t param = value + 1;
  while(!checkPrime(param)){
    param++
  }
  return param;
}

uint64_t sumPrime(uint64_t hbound) {
  // вставьте код функции
  return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  // вставьте код функции
  return 1;
}
