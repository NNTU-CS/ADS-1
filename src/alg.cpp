// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int l = 0, r = size - 1, n = 0;
  while (l < r) {
      int m = l + (r - l) / 2;
      if (value == arr[m]) {
          while (arr[m] == value)
              m--;
          m++;
          while (arr[m] == value) {
              n++;
              m++;
          }
          break;
      } else if (value < arr[m]) {
              r = m;
      } else {
          l = m + 1;
      }
  }
  return n;
  return 0; // если ничего не найдено
}
