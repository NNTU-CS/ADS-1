// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
	for (uint64_t i = 2; i <= value / 2; i++) {
		if (value % i == 0)
			return false;
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	int k = 0, a = 2;

	while (k != n) {
		for (uint64_t i = 2; i <= a / 2; i++) {
			if (a % i == 0) {
				k--;
				break;
			}
		}
		k++;
		a++;
	}
	return a - 1;
}

uint64_t nextPrime(uint64_t value) {
	uint64_t a = value + 1, flag = 0;

	while (flag == 0) {
		if (a > 1) {
			flag = 1;
			for (uint64_t i = 2; i <= a / 2; i++) {
				if (a % i == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return a;
		}
		a++;
	}
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t sum = 2, x = 3;

	if (hbound < 3)
		return 0;
	else {
		while (x < hbound) {
			for (uint64_t i = 2; i <= x / 2; i++) {
				if (x % i == 0) {
					sum -= x;
					break;
				}
			}
			sum += x;
			x++;
		}
		return sum;
	}
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	uint64_t k = 0, flag = 1;

	for (uint64_t i = lbound; i <= hbound - 3; i++) {
		flag = 1;
		for (uint64_t j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			for (uint64_t j = 2; j <= (i + 2) / 2; j++) {
				if ((i + 2) % j == 0) {
					flag = 0;
					break;
				}
			}
		}

		if (flag == 1)
			k++;
	}
	return k;
}