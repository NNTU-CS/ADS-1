// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
// вставьте код функции
  if (value <= 1) {
    return false;
}
if (value <= 3) {
    return true;
}

if (value % 2 == 0 || value % 3 == 0) {
    return false;
}

for (int i = 5; i * i <= value; i += 6) {
    if (value % i == 0 || value % (i + 2) == 0) {
        return false;
    }
}

return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
  if (n == 1) {
    return 2;
}
uint64_t count = 1;
uint64_t num = 3;
while (count < n) {
    if (checkPrime(num)) {
        count++;
    }
    if (count < n) {
        num += 2;
    }
}
return num;
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
   uint64_t num = value + 1;
 if (!checkPrime(num)) {
     num += 1;
 }
 return num;
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
   uint64_t sumch = 0;
 for (uint64_t i = 2; i < hbound; i++) {
     if (checkPrime(i)) {
         sumch += i;
     }
 }
 return sumch;
}
