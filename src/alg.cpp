// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
   int x = 0,
   int l = size - 1,
   int k = 0;
    while (x < l) {
      int mid = (x + l) / 2;
      if (arr[mid] < value)
        x = mid + 1;
      else
        l = mid;
      }
      if (arr[x] == value) {
        while (arr[x] == value) {
          k++;
          x++;
        }
      }
      if (k != 0)
        return k;
      else
        return 0;
}
