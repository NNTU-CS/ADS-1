// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

// Проверка, является ли число простым
bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    if (value == 2 || value == 3) {
        return true;
    }
    if (value % 2 == 0 || value % 3 == 0) {
        return false;
    }
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Нахождение n-го простого числа
uint64_t nPrime(uint64_t n) {
    uint64_t count = 0, num = 1;
    while (count < n) {
        ++num;
        if (checkPrime(num)) {
            ++count;
        }
    }
    return num;
}

// Поиск следующего простого числа
uint64_t nextPrime(uint64_t value) {
    while (true) {
        ++value;
        if (checkPrime(value)) {
            return value;
        }
    }
}

// Сумма всех простых чисел до hbound
uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

// Подсчет пар простых чисел-близнецов в диапазоне
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    uint64_t prev = 0;
    for (uint64_t i = lbound; i < hbound; ++i) {
        if (checkPrime(i)) {
            if (prev && i - prev == 2) {
                ++count;
            }
            prev = i;
        }
    }
    return count;
}
