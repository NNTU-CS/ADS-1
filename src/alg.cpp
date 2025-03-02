// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  int count = 1;
  for (int i = 2; i <= sqrt(value); ++i)
  {
	  if (value % i == 0)
		  count++;
	  if (count > 1)
		  return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
	if (n==1)
		return 2;
	int count = 1;
	for (int i = 3; count<n; i+=2)
	{
		if (checkPrime(i))
		{
			++count;
		}
		if (count == n)
			return i;
	}
}

uint64_t nextPrime(uint64_t value) {
	for (int i = value + 1; ; i++)
	{
		if (checkPrime(i))
			return i;
	}
}

uint64_t sumPrime(uint64_t hbound) {
	int sum = 2;//включено число 2
	for (int i = 3; i < hbound; i += 2)
	{
		if (checkPrime(i))
			sum += i;
	}
	return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (int i = lbound; i <= hbound - 2; ++i)
  {
	  if (checkPrime(i) && checkPrime(i + 2))
		  ++count;
  }  
  return count;
}
