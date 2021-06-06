// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int l, r, mid, count, m;
  l = 0; r = size-1; count = 0;
  mid = l + (r - l) / 2;
  while (l < r) {
    if (arr[mid] == value) {
      count += 1;
      m = mid;
      while (arr[mid] == value) {
        count += 1;
        mid -= 1; }
      mid = m;
      while (arr[mid+1] == value) {
        count += 1;
        mid += 1; }
      return count;
    } else if (arr[mid] > value) {
      r = mid;
    } else {
      l = mid + 1; }
  }
  return 0; }
