// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int s = 0;
  int h = size - 1;
  int n = 0;
  int y = 2;
  int k = 0;

  while (s < h) {
      k = (s + h) / y;
      if (arr[k] < value) {
          s = k + 1;
      } else {
          h = k;
      }
  }

  if (arr[s] == value) {
      while (arr[s] == value) {
          s++;
          n++;
      }
  }

  return n;
}
