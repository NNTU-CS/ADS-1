// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int l = 0, r = size - 1, res = 0;
  while (l < r) {
    int c = (l + r) / 2;
    if (arr[c] >= value)
      r = c;
    else
      l = c + 1;
    if (arr[l] == value) {
      while (arr[l] == value) {
        res++;
        l++;
      }
    }
  }
    return res;
}
