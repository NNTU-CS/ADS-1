// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
bool checkPrime(uint64_t value) {
if (value <= 1)
return false;
if (value == 2)
return true;
if (value % 2 == 0)
return false;
for (uint64_t i = 3; i*i <= value; i += 2) {
if (value % i == 0)
return false;
}
return true;
}
uint64_t nPrime(uint64_t n) {
uint64_t idx = 0;
uint64_t value = 2;
while (idx < n) {
if (checkPrime(value))
idx++;
value++;
}
return value-1;
}
uint64_t nextPrime(uint64_t value) {
if (value < 2)
return 2;
value++;
while (!checkPrime(value))
value++;
return value;
}
uint64_t sumPrime(uint64_t hbound) {
uint64_t summa = 0;
for (uint64_t i = 2; i < hbound; i++) {
if (checkPrime(i))
summa += i;
}
return summa;
}
