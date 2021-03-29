// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int i = 0;
  int j = size - 1;
  int c = 0; //counter
  while (i < j) {
    int middle = (i + j) / 2;
    if (arr[middle] < value)
      i = middle + 1;
    else
      j = middle;
    if (arr[i] == value) {
      while (arr[i] == value) {
        c++;
        i++;
      }
    }
  }
  if (c > 0)
    return c;
  else
    return 0; // если ничего не найдено
}
