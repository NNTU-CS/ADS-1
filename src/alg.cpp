// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
   if (value < 2) return false;
   if (value == 2) return true;
   if (value % 2 == 0) return false;
   for (uint64_t i = 3; i <= value*value; i += 2) {
      if (value % i == 0) return false;
   }
    return true;
}

uint64_t nPrime(uint64_t n) {
   if (n == 0) return 2;
   std::vector<uint64_t> primes;
   uint64_t num = 3;
   primes.push_back(2);
   while (primes.size() < n) {
      bool isPrime = true;
      for (uint64_t prime : primes) {
         if (prime * prime > num) break;
         if (num % prime == 0) {
            isPrime = false;
               break;
            }
         }
         if (isPrime) {
            primes.push_back(num);
         }
         num += 2;
      }
   return primes[n - 1];
}

uint64_t nextPrime(uint64_t value) {
   for (uint64_t num = value + 1; ; ++num) {
      if (CheckPrime(num)) return num;
   }
   return 2;
}

uint64_t sumPrime(uint64_t hbound) {
   uint64_t sum = 0;
   for (uint64_t i = 2; i < hbound; ++i) {
      if (CheckPrime(i)) {
         sum += i;
      }
   }
   return sum;
   return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
   uint64_t count = 0;
   std::vector<uint64_t> primes;

   for (uint64_t i = lbound; i < hbound; ++i) {
      if (isPrime(i)) {
         primes.push_back(i);
      }
   }

   for (size_t j = 1; j < primes.size(); ++j) {
      if (primes[j] - primes[j - 1] == 2) {
         count++;
      }
   }
   return count;
   return 1;
}
