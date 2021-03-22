// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int L = 0, R = size - 1, middle, numbers = 0;
  while (L < R) {
    middle = (L + R) / 2;
    if (arr[middle] < value)
      L = middle + 1;
    else
      R = middle;
  }
  if (arr[L] == value) {
    while (arr[L] == value) {
      numbers++;
      L++;
    }
  }
  if (numbers)
    return numbers;
  else
    return 0;
}
