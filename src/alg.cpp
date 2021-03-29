// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int i = 0, j = size - 1; //i - левая граница массива, j - правая
  int k = 0; //счетчик
  while (i < j) {
    int mid = (i + j) / 2;
    if (arr[mid] < value)
      i = mid + 1;
    else
      j = mid;
    if (arr[i] == value) {
      while (arr[i] == value) {
        k++;
        i++;
      }
    }
  }
  if (k > 0)
    return k;
  else
    return 0; // если ничего не найдено
}
