// Copyright 2022 NNTU-CS
#include <cstdint>
#include <vector>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) 
{
  if(value <= 1) 
	  return false;
  for (int i = 2; i <= sqrt(value); i++) 
  {
	  if (value % i == 0) 
		  return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) 
{
  if (n < 1) 
	  return 0;
  uint64_t count = 0; 
  uint64_t ch = 1; 
  while (count < n) 
  {
	  ch++;
	  if (checkPrime(ch)) 
		  count++;
  }
  return ch;
}

uint64_t nextPrime(uint64_t value) 
{
  uint64_t ch = value + 1;
  while (!checkPrime(ch))
	  ch++;
  return ch;
}

uint64_t sumPrime(uint64_t hbound) 
{
  int sum = 0;
  for (int i = 2; i <= hbound; i++) 
  {
	  if (checkPrime(i)) 
		  sum += i;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) 
{
  std::vector<bool> checkPrime(hbound, true);
  checkPrime[0] = checkPrime[1] = false; 
  for (uint64_t i = 2; i * i < hbound; ++i) 
  {
	  if (checkPrime[i]) 
	  {
		  for (uint64_t j = i * i; j < hbound; j += i) 
			  checkPrime[j] = false;
	  }
  }
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound - 2; ++i) 
  {
	  if (checkPrime[i] && checkPrime[i + 2]) 
		  count++;
  }
  return count;
}
