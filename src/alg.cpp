// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int i = 0, j = size - 1, count = 0;
    while (i < j) {
       int mid = i + (j-i) / 2;
        if (arr[mid] < value)
            i = mid + 1;
        else
          j = mid;
    }
    if (arr[i] == value) {
        while (arr[i] == value) {
            count++;
            i++;
        }
    }
        if (count != 0)
            return count;
        else
  return 0; // если ничего не найдено
}
