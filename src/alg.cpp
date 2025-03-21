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

uint64_t nPrime(int n) {
	if (n == 1) {
		return 2;
	}
	else {
		int num_ch = 1, kdel;
		for (int i = 3; i > 0;i++) {
			
			kdel = 0;
			for (int j = 2; j < i; j++) {
				if (i % j == 0) {
					kdel += 1;
				}
			}
			if (kdel == 0) {
				num_ch++;
			}
			if (n == num_ch) {
				return i;
				break;
			}
		}
	}
}

uint64_t nextPrime(uint64_t value) {
	int k;
	for (int i = value + 1; i > 0; i++) {
		k = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				k++;
			}
		}
		if (k == 0) {
			return i;
		}
	}
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
	for (int i = lbound; i < hbound-2; i ++) {
		k = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				k++;
			}
		}
		int q = i + 2;
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
return sch;
}
