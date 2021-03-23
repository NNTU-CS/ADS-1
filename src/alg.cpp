// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int bgn = 0;
  int end = size - 1;
  int cnt = 0;

  while (bgn < end) {
      int k = (bgn+end) / 2;
      if (arr[k] < value) {
          bgn = k+1;
      } else {
          end = k;
      }
  }

  if (arr[bgn] == value) {
      while (arr[bgn] == value) {
          bgn++;
          cnt++;
      }
  }

  return cnt;
}
