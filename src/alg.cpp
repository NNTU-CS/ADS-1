// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int i = 0, j = size - 1, k = 0;
  while (i < j) {
    int mid = i + (j - i) / 2;
    if (arr[mid] == value) {
      k += 1;
      int h = 1;
      while (arr[mid - h] == value) {
        k += 1;
        h += 1;
      }
      h = 1;
      while (arr[mid + h] == value) {
        k += 1;
        h += 1;
      }
      return k;
    } else if (arr[mid] > value) {
      j = mid;
    } else {
      i = mid + 1;
    }
    if (j == i) {
      if (arr[i] == value) {
        k += 1;
        return k;
      }
    }
  }
  return 0;
}
