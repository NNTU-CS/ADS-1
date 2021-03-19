// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int leftS = 0, count = 0;
  int rightS = size - 1;
  bool midCenter = true;
  int mid = (leftS + rightS) / 2;
  while (leftS <= rightS) {
    if (midCenter)
      mid = (leftS + rightS) / 2;
    if (arr[mid] == value) {
      midCenter = false;
      if (arr[mid-1] != value) {
        leftS = mid;
        while (arr[mid] == value) {
          count++;
          mid++;
          if (arr[mid] != value)
            return count;
        }
      } else {
        while (arr[mid-1] == value)
          mid--;
      }
    }
    if (arr[mid] > value)
      rightS = mid-1;
    if (arr[mid] < value)
      leftS = mid+1;
  }
  return 0; // если ничего не найдено
}

