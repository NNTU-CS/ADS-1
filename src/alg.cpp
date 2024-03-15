// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
bool checkPrime(uint64_t value) {
// вставьте код функции
if (value < 2)
  return false;
for (int k = 2; k < value; k++) {
  if (value % k == 0)
    return false;
}
  return true;
}
uint64_t nPrime(uint64_t n) {
// вставьте код функции
int count= 0;
uint64_t k = 2;
  while (count < n) {
    if (checkPrime(k))
      count++;
    k++;
  }
  return k - 1;
}
uint64_t nextPrime(uint64_t value) {
// вставьте код функции
uint64_t k = value + 1;
  while (!checkPrime(k)) {
    k++;
  }
  return k;
}
uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
uint64_t sum = 0;
  for (int k = 2; k < hbound; k++) {
    if (checkPrime(k))
      sum += k;
  }
  return sum;
}
 
