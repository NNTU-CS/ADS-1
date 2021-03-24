// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int counter = 0;

  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  if (arr[left] == value) {
    while (arr[left] == value) {
      counter++;
      left++;
    }
  }

  if (counter != 0) {
    return counter;
  } else {
    return 0;
  }
}
