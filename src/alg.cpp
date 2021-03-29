// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int c = 0, left = 0, right = size - 1;

  while (left < right) {
  int midd = (left + right) / 2;
  if (arr[midd] < value)
    left = midd + 1;
  else
    right = midd;
  }

  while (arr[left] == value) {
    c++;
    left++;
  }
  if (c != 0)
    return c;
  else
  return 0; // если ничего не найдено
}
