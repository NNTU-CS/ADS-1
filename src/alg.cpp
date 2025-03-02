// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
													
bool checkPrime(uint64_t value) {
  if (value < 2)
  	return false;
  for (uint64_t i = 2; i*i <= value; ++i) {
		  return false;
}
return true;  
} 

uint64_t nPrime(uint64_t n) 
{
	 if (n==0)
		return 0;
	 uint64_t count = 0, value = 2;
	 while (1)
		 {
			 if(checkPrime(value))
			 {
				 ++count;
			      if (count == n)
					 return value;
			 }
		 }
	++value;
}

uint64_t nextPrime(uint64_t value) {
	 for (uint64_t i = value + 1; ; i++)
	{
		  if (checkPrime(i))
			 return i;
	 }
}

uint64_t sumPrime(uint64_t hbound) {
	 uint64_t sum = 2;
	 for (uint64_t i = 3; i < hbound; i += 2)
	{
		  if (checkPrime(i))
			 sum += i;
	 }
	 return sum;
}


uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i <= hbound - 2; ++i)
  {
	   if (checkPrime(i) && checkPrime(i + 2))
		  ++count;
  }  
  return count;
}
