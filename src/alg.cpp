#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
// вставьте код функции
  int d = 1;
  for (int i = 1; i <= value / 2; i++)
    if (value % i == 0)
      d++;
  if (d != 2)
    return false;
  else
    return true;
}

uint64_t nPrime(uint64_t n) {
// вставьте код функции
  int a = 1, value = 1;
  while (a <= n) {
    if (checkPrime(value) == true)
      a++;
    value++;
  }
  return (value-1);
}

uint64_t nextPrime(uint64_t value) {
// вставьте код функции
  int j = value;
  while (true) {
    j++;
    if (checkPrime(j) == true)
      return j;
  }
}

uint64_t sumPrime(uint64_t hbound) {
// вставьте код функции
  int j = 1, s=0;
  while (j < hbound) {
    if (checkPrime(j) == true)
      s += j;
    j++;
  }
  return s;
}
