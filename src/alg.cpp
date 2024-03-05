// Copyright 2022 NNTU-CS 
#include <cstdint> 
#include "alg.h" 
 
bool checkPrime(uint64_t value) { 
  if (value <= 1) { 
      return false; 
  } 
  for (int i = 2; i <= value / 2; i++) { 
      if (value % i == 0) { 
          return false; 
      } 
  } 
  return true; 
} 
 
uint64_t nPrime(uint64_t n) { 
  int count = 0; 
  uint64_t num = 2;
  while (count < n) { 
      if (checkPrime(num)) { 
          count += 1; 
      } 
      if (count == n) { 
          return num; 
      } 
      num++;
  } 
  return 0; 
} 
 
uint64_t nextPrime(uint64_t value) { 
  uint64_t num = value + 1;
  while (true) { 
      if (checkPrime(num)) { 
          return num;
      } 
      num++;
  } 
} 
 
uint64_t sumPrime(uint64_t hbound) { 
  uint64_t sumOfPrime = 0; 
  for (uint64_t i = 2; i <= hbound; i++) { 
      if (checkPrime(i)) { 
          sumOfPrime += i; 
      } 
  } 
  return sumOfPrime; 
}
