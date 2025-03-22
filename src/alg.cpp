#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (int i = 2; i * i <= value; ++i) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n < 1) {
    return -1;
  }
  uint64_t count = 0;
  uint64_t number = 1;
  while (count < n) {
    number++;
    if (checkPrime(number)) {
      count++;
    }
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
	for (int i = value + 1; i > 0; i++) {
		int k = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				k++;
			}
		}
		if (k == 0) {
			return i;
		}
	}
	return -1;
}

uint64_t sumPrime(uint64_t hbound) {
	int sum = 0, k;
	for (int i = 2; i < hbound; i++) {
		k = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				k++;
			}
		}
		if (k == 0) {
			sum += i;
		}
	}
	return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int k, sch = 0;
  for (lbound; lbound < hbound - 2; lbound++) {
    k = 0;
    for (int j = 2; j < lbound; j++) {
      if (lbound % j == 0) {
        k++;
      }
    }
    int q = lbound + 2;
    if (k == 0) {
      k = 0;
      for (int i = 2; i < q; i++) {
        if (q % i == 0) {
          k++;
        }
      }
      if (k == 0) {
        sch++;
      }
    }
  }
  return sch;
}
