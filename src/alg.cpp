// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int g = 0;
  int s = size - 1;
  int point = 0;
  while (s > point) {
    int x = (s + point) / 2;
    if (arr[x] < value)
      point = x + 1;
    else
      s = x;
  }
  if (arr[point] == value) {
    while (arr[point] == value) {
      g++;
      point++;
    }
  }
  if (g)
    return g;
  else
    return 0;
}
