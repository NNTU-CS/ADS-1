// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int left = 0, right = size - 1, count = 0;
  while (left < right) {
  int s = (left + right) / 2; //находим середину массива
  if (arr[s] < value)
    left = s + 1;
  else
    right = s;
  }
  if (arr[left] == value) {
  while (arr[left] == value) {
    count++;
    left++;
  }
  }
  if (count)
    return count;
  else
  return 0; // если ничего не найдено
}
