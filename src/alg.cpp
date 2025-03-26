#include <cstdint>
#include <iostream>
#include "alg.h"
#include <vector>
using namespace std;

bool checkPrime(uint64_t value) {
	if (value <= 1) return false;
	if  (value <= 3) return true;
	if  (value % 2 == 0 || value % 3 == 0) return false;
	for  (uint64_t i = 5; i * i <= value; i += 6) {
		if (value % i == 0 || value % (i + 2) == 0) return false;
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	if (n == 0) return 0;
	uint64_t count = 0;
	uint64_t num = 1;
	while (count < n) {
		num++;
		if (checkPrime(num)) {
			count++;
		}
	}
	return num;
}

uint64_t nextPrime(uint64_t value) {
	if (value < 2) return 2;
	uint64_t nextValue = value + 1;
	while (!checkPrime(nextValue)) {
		nextValue++;
	}
	return nextValue;
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t sum = 0;
	for (uint64_t i = 2; i < hbound; i++) {
		if (checkPrime(i)) {
			sum += i;
		}
	}
	return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	if (hbound < 2) return 0;
	vector<bool> isPrime(hbound + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (uint64_t i = 2; i * i <= hbound; ++i) {
		if (isPrime[i]) {
			for (uint64_t j = i * i; j <= hbound; j += i) {
				isPrime[j] = false;
			}
		}
	}
	uint64_t count = 0;
	for (uint64_t i = max(lbound, 2ULL); i + 2 <= hbound; ++i) {
		if (isPrime[i] && isPrime[i + 2]) {
			++count;
		}
	}
	return count;
}
