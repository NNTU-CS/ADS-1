// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <vector>


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  for (uint64_t i = 2; i*i <= value; i++)
  {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  std::vector<uint64_t> numbers;
  uint64_t num = 2;
  while (numbers.size() < n) {
    if (checkPrime(num)) {
      numbers.push_back(num);
    }
    num++;
  }
  return numbers[numbers.size() - 1];
	
}

uint64_t nextPrime(uint64_t value) {
	if (checkPrime(value)) {
		return true;
	}
	else {
		value++;
	}
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t num = 2;
	uint64_t counter = 0;
	while (num < hbound) {
		if (checkPrime(num)) {
			counter = counter + num;
		}
	}
	return counter;
}
