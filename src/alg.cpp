// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
 if (value < 2) return false;
 if (value == 2) return true;
 if (value % 2 == 0) return false;

 for (uint64_t i = 3; i * i <= value; i += 2) {
  if (value % i == 0) {
   return false;
   }
 }
    
 return true;
}

uint64_t nPrime(uint64_t n) {
 if (n == 1) return 2; 
 uint64_t count = 1;
 uint64_t num = 3;
    
 while (count < n) {
  if (CheckPrime(num)) {
   count++;
  }
  num += 2;
 }
    
 return num - 2;
}

uint64_t nextPrime(uint64_t value) {
 if (value < 2) return 2;
    
 uint64_t next = value + 1;
 while (!CheckPrime(next)) {
  next++;
 }
    
 return next;
}

uint64_t sumPrime(uint64_t hbound) {
 uint64_t sum = 0;
 for (uint64_t i = 2; i < hbound; ++i) {
  if (CheckPrime(i)) {
   sum += i;
  }
 }
    
 return sum;
}
