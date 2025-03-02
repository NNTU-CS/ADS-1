// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

// Функция проверки, является ли число простым. Изменен алгоритм немного.
bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value <= 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i * i <= value; i = i + 6) {
    if (value % i == 0 || value % (i + 2) == 0)
      return false;
  }
  return true;
}

// Находит n-ое простое число
uint64_t nPrime(uint64_t n) {
  if (n == 1) return 2;
  uint64_t count = 1;
  uint64_t number = 3;
  while (count < n) {
    if (checkPrime(number)) {
      count++;
    }
    if (count < n) {
      number += 2;
    }
  }
  return number;
}

// Находит следующее простое число после value
uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  uint64_t next = value + 1;
  if (value > 2 && value % 2 == 0) next++;
  while (!checkPrime(next)) {
    next++;
    if (next % 2 == 0) next++;
  }
  return next;
}

// Сумма простых чисел до hbound
uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  uint64_t sum = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

// Количество пар простых чисел-близнецов в диапазоне [lbound, hbound)
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  if (lbound < 3) lbound = 3;
  for (uint64_t i = lbound; i < hbound - 1; i++) {
    if (lbound > 2 && i % 2 == 0) continue;
    if (checkPrime(i) && checkPrime(i + 2) && ((i + 2) < hbound)) {
      count++;
    }
  }
  return count;
}
