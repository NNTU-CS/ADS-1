// Copyright 2021 NNTU-CS
#include "alg.h"

int cbinsearch(int* arr, int size, int value) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == value)
      count++;
  }

  return count;
}
