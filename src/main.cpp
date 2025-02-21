// Copyright 2022 NNTU-CS
#include "../include/alg.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << twinPrimes(atoi(argv[1]), atoi(argv[2])) << std::endl;
  return 0;
}
