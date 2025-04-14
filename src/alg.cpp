// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
   if (value < 2) {
    return false;
  }

  for (uint64_t test = 2; test * test <= value; ++test) {
    if (value % test == 0) {
      return false;
    }
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
 uint64_t fo = 0;
  uint64_t cur = 1;

  while (f < targetIndex) {
    ++cur;
    if (checkPrime(cur)) {
      ++fo;
    }
  }

  return cur;
}

uint64_t nextPrime(uint64_t value) {
 uint64_t next = from + 1;

  while (!checkPrime(next)) {
    ++next;
  }

  return next;
}

uint64_t sumPrime(uint64_t hbound) {
   uint64_t summ = 0;

  for (uint64_t vall = 2; vall < upperLimit; ++vall) {
    if (checkPrime(vall)) {
      summ += vall;
    }
  }

  return summ;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t twin = 0;
  uint64_t last = 0;

  for (uint64_t i = lo; i < hig; ++i) {
    if (checkPrime(i)) {
      if (last && i - last == 2) {
        ++twin;
      }
      last = i;
    }
  }

  return twin;
}
