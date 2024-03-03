// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
for (int i = 2; i * i <= value; i++) {
		if (value % i == 0) {
			return false;
		}
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
int k = 0;
	for (uint64_t i = 2; ; i++) {
		bool is_prime = checkPrime(i);
		if (is_prime == true) {
			k++;
			if (k == n){
				return i;
			}
		}
	}
}

uint64_t nextPrime(uint64_t value) {
for (uint64_t i = value + 1; ; i++) {
		bool is_prime = checkPrime(i);
		if (is_prime == true)
		return i;
}
}
uint64_t sumPrime(uint64_t hbound) {
uint64_t sum = 0;
	for (uint64_t i = 2; i <= hbound ; i++) {
		bool is_prime = checkPrime(i);
		if (is_prime == true) {
			sum = sum + i;

		}
	}
	return sum;
}
