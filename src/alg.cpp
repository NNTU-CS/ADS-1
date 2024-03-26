// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
        bool result = true;
         if (value > 1) {
          int j = 0;
           for (j = 2; j * j <= value; j++) {
                     if (value % j == 0) {
                         result = false;
                         break;
                        }
                  }
             } else {
                 result = false;
               }
         return result;
}

uint64_t nPrime(uint64_t n) {
        uint64_t result = 0;
        uint64_t temp_count  = 0;
        uint64_t temp_number = 1;
        if (n <= 0) {
               return result;
           }
           while (temp_count < n) {
                 temp_number++;
                 if (checkPrime(temp_number)) {
                        temp_count++;
                    }
               }
               result = temp_number;
          return result;
}

uint64_t nextPrime(uint64_t value) {
       uint64_t result = 0;
       uint64_t temp_n = value+1;
        while (1) {
              if (checkPrime(temp_n)) {
                   result = temp_n;
                    break;
                 }
                 temp_n++;
              }
             return result;
  }

uint64_t sumPrime(uint64_t hbound) {
        uint64_t tempSum = 0;
         for (uint64_t j = 2; j < hbound; j++) {
                 if (checkPrime(j)) {
                     tempSum = tempSum + j;
                  }
            }
            return tempSum;
}
