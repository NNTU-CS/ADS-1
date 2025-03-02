// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if(value < 2){
    return false;
  }
  for(int i = 2; i < value; i++){
      if (value % i == 0){
  return false;
  }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t c = 0;
  uint64_t num = 1;
  while (c < n){
  num +=1;
      if (checkPrime(num)){
  c += 1;
  }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t c = value + 1;
  while(1){
      if(checkPrime(c)){
  return c;
  }
  c +=1;
  }
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for(int i  = 2; i < hbound; i++){
      if(checkPrime(i)){
  sum += i;
  }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int c = 0;
  for(uint64_t  i = lbound; i < hbound - 2; i++){
      if(checkPrime(i)){
          if(checkPrime(i + 2)){
  c += 1;
  }
  }
  }
  
  return c;
}
