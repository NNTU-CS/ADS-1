// Copyright 2022 NNTU-CS
#include "../include/alg.h"

#include <cmath>
#include <cstdint>

// Функция возвращает true, если число value простое и false в противном случае.
bool checkPrime(uint64_t value) {
  // вставьте код функции
  if (value <= 1)
    return false;
  uint64_t array = 2;
  for (uint64_t i = static_cast<uint64_t>(pow(value, 0.5)) + 1; i > 1; i--) {
    if (value % i == 0) {
      array++;
    }
  }
  if (array == 2 || value == 2) {
    return true;
  }
  return false;
}
// Функция возвращает найденное простое число.
uint64_t nPrime(uint64_t n) {
  for (uint64_t i = 1;; i++) {
    if (checkPrime(i)) {
      n--;
    }
    if (n == 0) {
      return i;
    }
  }
}
// Функция возвращает следующее простое число после value.
uint64_t nextPrime(uint64_t value) {
  // вставьте код функции
  while (1) {
    value++;
    if (checkPrime(value)) {
      return value;
    }
  }
}

uint64_t sumPrime(uint64_t hbound) {
  // вставьте код функции
  uint64_t n = hbound - 1;
  uint64_t sum = 0;
  while (n > 1) {
    if (checkPrime(n)) {
      sum += n;
    }
    n--;
  }
  return sum;
}
// Простыми числами-близнецами называют простые числа, отличающиеся друг от
// друга на 2. Например, 3,5, 5,7, 11,13. Функция должна находить количество пар
// простых чисел-близнецов в диапазоне от lbound до hbound. если в диапазон
// попадает только одно число из пары, то такая пара не считается. Верхняя
// граница в числовой диапазон не включается! То есть, если диапазон задан как
// [2,101), то реальный интервал чисел - от 2 до 100. Функция возвращает
// количество пар чисел в заданном диапазоне. Например, в диапазоне [2,10)
// содержатся 2 пары.
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  // вставьте код функции
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 1; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }
  return count;
}
