// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int counter = 0;
  while (left < right) {
    int m = (left + right) / 2;
    if (arr[m] < value)
      left = m + 1;
    else
      right = m;
  }
  if (arr[left] == value) {
    while (arr[left] == value) {
      counter = counter + 1;
      left = left + 1;
    }
  }
  if (counter)
    return counter;
  else
  return 0; // если ничего не найдено
}
