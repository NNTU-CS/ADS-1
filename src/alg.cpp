// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2)
	  return false;
  for (int i = 2; i <= sqrt(value); i++)
	  if (value % i == 0)
		  return false;
  return true;
}

uint64_t nPrime(uint64_t n) {
  int count = 0;
  int num = 1;
  while (count < n) {
  	num++;
  	if (checkPrime(num)) 
  		count++;
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  int next = value + 1;
  while (!checkPrime(next))
  	next++;
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++)
  	if (checkPrime(i))
  		sum += i;
}
