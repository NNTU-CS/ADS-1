// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int a = 0, left = 0, right = size - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] < value)
      left = mid + 1;
    else
      right = mid;
  }
  while (arr[left] == value) {
    a++;
    left++;
  }
  if (a != 0)
    return a;
  else
return 0;
}
