// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int right = 0, left = size - 1, sum = 0;
  while (right < left) {
    int mid = (right + left) / 2;//
    if (arr[mid] < value)//
      right = mid + 1;
    else
      left = mid;
  }
  if (arr[right] == value) {
    while (arr[right] == value) {
      sum++;
      right++;
    }
  }
  if (sum != 0)
    return sum;
  else
    return 0;//если ничего не найдено
}
