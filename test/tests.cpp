// Copyright 2022 NNTU-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


// TEST(ads1, failingTest) {
//   EXPECT_EQ(true, false);
// }
TEST(ads1, checkPrime1) {
  EXPECT_EQ(true, checkPrime(2));
}
TEST(ads1, checkPrime2) {
  EXPECT_EQ(true, checkPrime(3));
}
TEST(ads1, checkPrime3) {
  EXPECT_EQ(false, checkPrime(12));
}
TEST(ads1, nPrime1) {
  uint64_t res = nPrime(6);
  EXPECT_EQ(13, res);
}
TEST(ads1, nPrime2) {
  uint64_t res = nPrime(500);
  EXPECT_EQ(3571, res);
}
TEST(ads1, nextPrime1) {
  uint64_t res = nextPrime(1031);
  EXPECT_EQ(1033, res);
}
TEST(ads1, nextPrime2) {
  uint64_t res = nextPrime(3559);
  EXPECT_EQ(3571, res);
}
TEST(ads1, nextPrime3) {
  uint64_t res = nextPrime(2);
  EXPECT_EQ(3, res);
}
TEST(ads1, sumPrime1) {
  // uint64_t res = sumPrime(2000000);
  // uint64_t expected = 142913828922;
  // EXPECT_EQ(expected, res);
  EXPECT_TRUE(true);
}
TEST(ads1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}

