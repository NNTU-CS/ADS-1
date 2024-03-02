// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
#include <cmath>


bool checkPrime(uint64_t value) {
	if (value <= 1) {
		return false;
	}
	for (uint64_t i = 2; i <= sqrt(value); i++) {
		if (value % i == 0) {
			return false;
		}
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	uint64_t num = 2;
	uint64_t count = 0;

	while (count < n) {
		if (checkPrime(num)) {
			count++;
		}
		num++;
	}

	return num - 1;
}

uint64_t nextPrime(uint64_t value) {
	uint64_t num = value + 1;

	while (!checkPrime(num)) {
		num++;
	}

	return num;
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t sum = 0;

	for (uint64_t i = 2; i < hbound; i++) {
		if (checkPrime(i)) {
			sum += i;
		}
	}

	return sum;
}
int main() {
	uint64_t number; //вводимое на проверку число
	std::cin >> number;
	uint64_t n; //ряд числа
	std::cin >> n;
	std::cout << "Is " << number << " prime? " << std::boolalpha << checkPrime(number) << std::endl;
	std::cout << "The " <<  n << " th prime number is: " << nPrime(n) << std::endl;
	std::cout << "Next prime number after " << number << " is: " << nextPrime(number) << std::endl;
	std::cout << "Sum of all prime numbers up to " << number << " is: " << sumPrime(number) << std::endl;

	return 0;
}

