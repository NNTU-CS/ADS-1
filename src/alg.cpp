// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
bool checkPrime(uint64_t value) {
for (uint64_t i = 2; i*i <= value; ++i) {
  if (value % i == 0)
    return false;
}
    return true;
}
uint64_t nPrime(uint64_t n) {
int c = 0;
int num = 1;
while (c < n) {
  num++;
  if (checkPrime(num)) {
    c++;
  }
}
return num;
}
uint64_t nextPrime(uint64_t value) {
int num = ++value;
while (!checkPrime(num)) {
  num++;
  }
  return num;
}
uint64_t sumPrime(uint64_t hbound) {
uint64_t sum = 0;
for(int num = 2; num < hbound; num++) {
  if (checkPrime(num))
      sum += num;
  }
  return sum;
}
