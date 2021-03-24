// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int l = 0, r = size - 1, m, total = 0;

  while (l < r) {
    m = (l + r) / 2;
    if (arr[m] < value) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  while (arr[l] == value) {
    total++; l++;
  }

return total;
}
