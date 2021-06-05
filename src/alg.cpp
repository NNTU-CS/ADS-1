// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
int right = size;
int left = 0;
int count = 0;
int average;
  while (left < right) {
    average = (left + right) / 2;
    if (arr [mid] == value) {
      for (int i = average; arr [i] == value; i++) {
        if (arr [average] == value) {
          count++;
        }
      }
      for (int j = average - 1; arr[j] == value; j--) {
        if (arr [average] == value) {
          count++;
        }
      }
      break;
    }
    else if (arr [average] > value) {
      right = average;
    }
    else {
      left = average + 1;
    }
  }
  return count;
}
