// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (int i = 2; i < value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t i = 2;
  uint64_t m_cnt = 0;
  uint64_t m_cons = 0;
  while (m_cnt != n) {
    uint64_t k1 = 0;
    for (uint64_t j = 2; j < i; j++) {
      if (i % j == 0) {
        k1++;
        break;
      }
    }
    if (k1 == 0) {
      m_cnt++;
      m_cons = i;
    }
    i++;
  }
  return m_cons;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t m_cnt = 0;
  uint64_t m_res = 0;
  uint64_t i = value + 1;
  while (m_cnt != 1) {
    uint64_t k1 = 0;
    for (uint64_t j = 2; j < i; j++) {
      if (i % j == 0) {
        k1++;
        break;
      }
    }
    if (k1 == 0) {
      m_cnt++;
      m_res = i;
    }
    i++;
  }
  return m_res;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sns = 0;
  uint64_t i = 2;
  while (i < hbound) {
    uint64_t k1 = 0;
    for (uint64_t j = 2; j < i; j++) {
      if (i % j == 0) {
        k1++;
        break;
      }
    }
    if (k1 == 0) {
      sns += i;
    }
    i++;
  }
  return sns;
}
