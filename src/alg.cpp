// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int s = 0, count = 0, k = 0;
  while (true) {
    s = (size + k) / 2;
    if (value < arr[s]) {
      size = s - 1;
    } else if (value > arr[s]) {
      k = s + 1;
    } else {
      while (arr[s] == value) {
        s--;
      }
      s++;
      while (arr[s] == value) {
        count++;
        s++;
      }
      break;
    }
    if (k > size) {
      break;
    }
  }
  return count;
}
