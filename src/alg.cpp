// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	if (value == 1)
		return false;
	if (value % 2 == 0)
		return false;
	for (int i = 3; i < value / 2; i += 2) {
		if (value % i == 0)
			return false;
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	int number = 1;
	int primeNumber = 0;
	int i = 3;
	if (n == 1)
		return 2;
	while (number != n) {
		if (checkPrime(i))
			number++;
		primeNumber = i;
		i += 2;
	}
	return primeNumber;
}

uint64_t nextPrime(uint64_t value) {
	while (!checkPrime(value + 1)) {
		value++;
	}
	return value + 1;
}

uint64_t sumPrime(uint64_t hbound) {
	if (hbound < 3)
		return 0;
	int n = 2;
	int addition = 2;
	while (n < hbound) {
		n = nextPrime(n);
		addition += n;
	}
	return addition - n;
}
