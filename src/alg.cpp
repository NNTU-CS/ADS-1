// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int left, right, midle, count;
  left = 0;
  right = size - 1;
  count = 0;
  while (left < right) {
    midle = (left+right) / 2;
    if (*(arr+midle) < value)
      left = midle + 1;
    else
      right = midle;
}
  if (*(arr + left) == value) {
    while (*(arr+left) == value) {
      count++;
      left++;
}
}
return count;
}
