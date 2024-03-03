// src/alg.cpp

#include <iostream>
#include <vector>

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (uint64_t i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }

    uint64_t count = 1;
    uint64_t num = 3;

    while (count < n) {
        if (checkPrime(num)) {
            ++count;
        }
        if (count < n) {
            num += 2;
        }
    }

    return num;
}

uint64_t nextPrime(uint64_t value) {
    if (value < 2) {
        return 2;
    }

    uint64_t num = value + 1;
    while (!checkPrime(num)) {
        ++num;
    }

    return num;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;

    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }

    return sum;
}

int main() {

    uint64_t value = 23;
    std::cout << value << " is prime: " << std::boolalpha << checkPrime(value) << std::endl;

    uint64_t n_value = 5;
    std::cout << "The " << n_value << "-th prime number is: " << nPrime(n_value) << std::endl;

    uint64_t next_value = 17;
    std::cout << "The next prime after " << next_value << " is: " << nextPrime(next_value) << std::endl;

    uint64_t sum_bound = 30;
    std::cout << "Sum of primes up to " << sum_bound << " is: " << sumPrime(sum_bound) << std::endl;

    return 0;
}
