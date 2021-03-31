// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
  int left = 0, right = size - 1, middle, k = 0;
  while (left <= right) {
    middle = (left + right) / 2;
    if (arr[middle] == value)
      break;
    if (arr[middle] > value)
      right = middle - 1;
    if (arr[middle] < value)
      left = middle + 1;
  }
  for (int i = middle; arr[i] == value; ++i) {
        k = k + 1;
        if (i == size - 1)
          break;
      }
      for (int j = middle - 1; arr[j] == value; --j) {
        k = k + 1;
        if (j == 0)
          break;
      }
  return k;
}
