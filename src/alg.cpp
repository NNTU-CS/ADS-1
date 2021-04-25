// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int f = 0, a = 0, b = size - 1;
  while (a < b) {
    int c = (a + b) / 2;
    if (arr[c] < value)
      a = c;
    else
      b = c;
  }
  while (arr[a] == value) {
    f++;
    a++;
  }
  if (f != 0)
    return f;
  else
return 0;
}
