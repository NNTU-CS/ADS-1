// Copyright 2022 NNTU-CS
#include <iostream>
#include "alg.h"

int main() {
  uint64_t value = 29;
  uint64_t n = 10;
  uint64_t hbound = 50;
  uint64_t lbound = 2;
  std::cout << checkPrime(value) << std::endl;
  std::cout << nPrime(n) << std::endl;
  std::cout << nextPrime(value) << std::endl;
  std::cout << sumPrime(hbound) << std::endl;
  std::cout << twinPrimes(lbound, hbound) << std::endl;
  return 0;
}
