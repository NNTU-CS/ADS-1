// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int f = 0;
  int a = 0;
  int b = size - 1;
  while (a < b) {
    int c = (a + b) / 2;
    if (arr[c] < value)
      a = c + 1;
    else
      b = c;
  }
  if (arr[a] == value) {
  while (arr[a] == value) {
    f++;
    a++;
  }
  }
  if (f)
    return f;
  else
    return 0;
}
