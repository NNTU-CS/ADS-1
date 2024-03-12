// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  for (int i=2; i < value; i++) {
        if (value%i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
  int nomer = 0;
  int chislo = 2;
  int save;
    while (nomer < n) {
    int schetprost = 0;
      for (int i=1; i <= chislo;  i++) {
        if (chislo%i == 0) {
          schetprost = schetprost+1;
        }
      }
    if (schetprost < 3) {
        save = chislo;
        nomer = nomer+1;
    }
    chislo = chislo+1;
}
return save;
}

uint64_t nextPrime(uint64_t value) {
    int chislo = value+1;
    int schet = 0;
    int save;
    bool f = true;
    while (f == true) {
        for (int i=1; i <= chislo; i++) {
            if (chislo%i == 0) {
                schet = schet+1;
            }
        }
        if (schet > 2) {
            schet = 0;
            chislo = chislo+1;
        }
        else {
          f = false;
          save = chislo;
        }
    }
    return save;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sm = 0;
  for (uint64_t i = 2; i < hbound; i++) {
      if (checkPrime(i)) {
          sm = sm + i;
      }
  }
  return sm;
}
